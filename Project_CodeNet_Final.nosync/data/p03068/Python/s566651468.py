# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 20:18:25 2019

@author: screamLab
"""

n = int(input())
s = input()
k = int(input())

mark = s[k - 1]
new = []
for i in range(n):
    new.append(s[i])
for i in range(n):
    if(new[i] != mark):
       new[i] = '*'
print(''.join(new))