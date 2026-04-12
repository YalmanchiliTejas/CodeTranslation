#!/usr/bin/env python
# -*- coding: utf-8 -*-
# sequence decomposing
import bisect
n = int(input())
lists = [int(input()) for _ in range(n)]
lists = lists[::-1]
dataset = []
dataset.append(lists[0])
# datasetは単調増加なリストの値
for i in range(1, n):
    x = lists[i]
    if x >= dataset[-1]:
        dataset.append(x)
    elif x < dataset[-1]:
        index = bisect.bisect_right(dataset, x)
        dataset[index] = x
print(len(dataset))