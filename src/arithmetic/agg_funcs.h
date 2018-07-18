/*
* Copyright 2018-2019 Redis Labs Ltd. and Contributors
*
* This file is available under the Apache License, Version 2.0,
* modified with the Commons Clause restriction.
*/

#ifndef __AGG_FUNCTIONS_H__
#define __AGG_FUNCTIONS_H__

#include "agg_ctx.h"

typedef AggCtx* (*AggFuncInit)(void);

AggCtx* Agg_SumFunc();
AggCtx* Agg_AvgFunc();
AggCtx* Agg_MaxFunc();
AggCtx* Agg_MinFunc();
AggCtx* Agg_CountFunc();
AggCtx* Agg_PercContFunc();
AggCtx* Agg_PercDiscFunc();
AggCtx* Agg_stDev();

void Agg_RegisterFuncs();

#endif