#!/usr/bin/env python
# -*- coding: utf-8 -*-

N = int(input())
H = map(lambda x: int(x), input().split(' '))

maxH = 0
result = 0
for h in H:
    if h >= maxH:
        result += 1
        maxH = h
print(result)
