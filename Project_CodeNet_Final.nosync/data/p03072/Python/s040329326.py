#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 26 17:52:43 2019

@author: nakamuratakayuki
"""

N = int(input())
Hlist = list(map(int, input().split()))
c = 1
for i in range(1,N):
    if Hlist[i] >= max(Hlist[:i]):
        c += 1
print(c)