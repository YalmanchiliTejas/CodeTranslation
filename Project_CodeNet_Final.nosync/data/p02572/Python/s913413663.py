# -*- coding: utf-8 -*-
"""
Created on Sat Aug 29 22:19:15 2020

@author: naoki
"""

N = int(input())

A = list(map(int,input().split()))

count1 = 0
count2 = 0
count = 10**9 +7
for i in A:
    count1+=i

for j in A:
    count2 = (j*(count1-j) + count2)%count
    count1 = count1 -j 
    
print(count2%count)
    
    
    