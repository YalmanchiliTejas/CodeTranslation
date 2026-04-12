# -*- coding: utf-8 -*-
"""
Created on Sun Apr 21 13:54:29 2019

@author: Yamazaki Kenichi
"""

N = int(input())
S = input()
K = int(input())

ans = ''
key = S[K-1]
for c in S:
    if c != key:
        ans += '*'
    else:
        ans += c
print(ans)