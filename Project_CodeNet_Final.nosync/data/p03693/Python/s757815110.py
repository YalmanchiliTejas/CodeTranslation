# -*- coding: utf-8 -*-
"""
Created on Sun Feb 24 02:00:50 2019

@author: yuta
"""

def judge(r,g,b):
    ans = 100*r + 10*g + b
    if ans % 4 == 0:
        print("YES")
    else:
        print("NO")
        
x = input().split()
judge(int(x[0]),int(x[1]),int(x[2]))