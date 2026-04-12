# -*- coding: utf-8 -*-
"""
Created on Sat Apr 13 20:57:38 2019

@author: Yamazaki Kenichi
"""

N = int(input())
H = list(map(int,input().split()))

ans = 0
h0 = H[0]
for h in H:
    if h0 <= h:
        ans += 1
        h0 = h

print(ans)