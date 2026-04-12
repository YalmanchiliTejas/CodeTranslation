#! /usr/bin/env python3
# -*- coding: utf-8 -*-
N = int(input())
Hlist = [int(x) for x in input().split()]

count = 0
for i in range (N):
    if Hlist[i] >= max(Hlist[0:i+1]):
        count+= 1

print(count)
