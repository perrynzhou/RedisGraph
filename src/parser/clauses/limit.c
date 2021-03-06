/*
* Copyright 2018-2019 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#include "./limit.h"

AST_LimitNode* New_AST_LimitNode(int limit) {
	AST_LimitNode* limitNode = (AST_LimitNode*)malloc(sizeof(AST_LimitNode));
	limitNode->limit = limit;
	return limitNode;
}

void Free_AST_LimitNode(AST_LimitNode* limitNode) {
	if(limitNode) {
		free(limitNode);
	}
}
