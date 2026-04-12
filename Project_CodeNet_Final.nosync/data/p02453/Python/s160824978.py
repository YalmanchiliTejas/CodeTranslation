# -*- coding: utf-8 -*-
"""
Binary Search - Lower Bound
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_6_C&lang=jp

"""
from bisect import bisect_left

n = int(input())
A = [int(a) for a in input().split()]
for _ in range(int(input())):
    i = bisect_left(A, int(input()))
    print(n if i == n else i)

