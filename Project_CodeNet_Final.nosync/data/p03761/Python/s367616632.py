#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf')
ans = 0 ;count = 0 ;pro = 1

n=int(input())
S=[input() for i in range(n)]
data=[inf]*26
for s in S:
    tmp=[0]*26
    for si in s:
        tmp[ord(si)-ord("a")]+=1
    for i in range(26):
        data[i]=min(data[i],tmp[i])
ans=""
# print(data)
for i in range(26):
    # print(ans)
    ans+=chr(ord("a")+i)*data[i]
print(ans)

