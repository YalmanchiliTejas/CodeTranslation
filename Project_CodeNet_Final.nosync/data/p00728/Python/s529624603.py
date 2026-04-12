#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Problems 1157
Problem A: ICPC 得点集計ソフトウェア
"""
while True:
    n = int(input())
    if  n == 0:
        break
    sum, s_min, s_max = 0, 1001, -1
    for i in range(n):
        score = int(input())
        s_min = min(s_min, score)
        s_max = max(s_max, score)
        sum += score
    print((sum-s_min-s_max)//(n-2))

