# -*- coding: utf-8 -*-
"""
Created on Tue Mar 31 11:16:07 2020

@author: liang
"""

A, B, C, X, Y = map(int,input().split())
if A + B > 2*C:
    if X > Y :
        if A < 2 * C:
            ans = Y * C * 2 + abs(X-Y) * A
        else:
            ans = X * C * 2
    else:
        if B < 2 * C:
            ans = X * C * 2 + abs(X-Y) * B
        else:
            ans = Y * C * 2
else:
    ans = X * A + Y * B 
print(ans)