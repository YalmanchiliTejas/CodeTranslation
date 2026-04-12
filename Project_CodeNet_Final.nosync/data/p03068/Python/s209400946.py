# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 21:06:53 2019

@author: doppe
"""

N = int(input())
S = input()
K = int(input())

ans = ""
for c in S:
    if (c == S[K - 1]):
        ans += c
    else:
        ans += '*'
print(ans)