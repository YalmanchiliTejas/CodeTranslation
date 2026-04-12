# -*- coding: utf-8 -*-
"""
Created on Sun Aug 28 21:42:33 2016

@author: you
"""

n = list(map(int, input().split()))
l = n[0] * 100 + n[1] * 10 + n[2]
m = l % 4
if m == 0:
    ans = "YES"
else:
    ans = "NO"
print(ans)    
