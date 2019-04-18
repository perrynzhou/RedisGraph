/*
* Copyright 2018-2019 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#ifndef QUERY_GRAPH_H_
#define QUERY_GRAPH_H_

#include "entities/node.h"
#include "entities/edge.h"
#include "graph.h"
#include "graphcontext.h"
#include "../parser/newast.h"

#define DEFAULT_GRAPH_CAP 32 /* Number of edges/nodes within the graph. */

typedef struct {
    Node **nodes;
    Edge **edges;
    char **node_aliases;
    char **edge_aliases;
} QueryGraph;

/* Prepare a new query graph with initial allocations for
 * the provided node and edge counts. */
QueryGraph* QueryGraph_New(size_t node_cap, size_t edge_cap);

/* Add all nodes and relationships from a single path
 * (from part of a MATCH or CREATE pattern, or a MERGE clause)
 * to the QueryGraph. */
void QueryGraph_AddPath(const GraphContext *gc, const NEWAST *ast, QueryGraph *qg, const cypher_astnode_t *path);

/* Adds all paths described in an AST pattern node (from a
 * MATCH or CREATE clause) to a meta-graph that describes all
 * nodes and relationships in a query. */
QueryGraph* BuildQueryGraph(const GraphContext *gc, const NEWAST *ast);

/* Checks if graph contains given node
 * Returns 1 if so, 0 otherwise */
int QueryGraph_ContainsNode(const QueryGraph *qg, const Node *node);

int QueryGraph_ContainsEdge(const QueryGraph *qg, const Edge *edge);

/* Retrieves node from graph */
Node* QueryGraph_GetNodeById(const QueryGraph *qg, long int id);

/* Retrieves node from graph */
Edge* QueryGraph_GetEdgeById(const QueryGraph *qg, long int id);

/* Search the graph for a node with given alias */
Node* QueryGraph_GetNodeByAlias(const QueryGraph *qg, const char *alias);

/* Search the graph for an edge with given alias */
Edge* QueryGraph_GetEdgeByAlias(const QueryGraph *qg, const char *alias);

/* Search for either node/edge with given alias. */
GraphEntity* QueryGraph_GetEntityByAlias(const QueryGraph *qg, const char *alias);

/* Adds a new node to the graph */
void QueryGraph_AddNode(QueryGraph *qg, Node *n, char *alias);

/* Adds a new edge to the graph */
void QueryGraph_ConnectNodes(QueryGraph *qg, Node *src, Node *dest, Edge *e, char *edge_alias);

GraphEntity** QueryGraph_GetEntityRef(const QueryGraph *qg, const char *alias);
Node** QueryGraph_GetNodeRef(const QueryGraph *qg, const Node *n);
Edge** QueryGraph_GetEdgeRef(const QueryGraph *qg, const Edge *e);

/* Frees entire graph */
void QueryGraph_Free(QueryGraph* qg);

#endif
