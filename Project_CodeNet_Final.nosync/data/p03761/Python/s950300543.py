# -*- coding: utf-8 -*-
"""
Created on Sat Sep  8 10:15:40 2018

@author: maezawa
"""
import collections
n = int(input())
arr = []
for i in range(n):
    arr.append(collections.Counter(input()))
    
common = arr[0]
for key, value in common.items():
    for i in range(1,n):
        if arr[i][key] < common[key]:
            common[key] = arr[i][key]

ans = ''
for key, value in common.items():
    ans += key*value

ans = ''.join(sorted(list(ans)))

print(ans)


