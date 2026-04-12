#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    n = int(input())
    if n == 0:
        break
    P = [int(input()) for i in range(0,n)]
    print((sum(P) - min(P) - max(P))//(n-2))