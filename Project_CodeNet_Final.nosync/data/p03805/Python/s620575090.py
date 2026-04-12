#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
sys.setrecursionlimit(10**7)
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf')
ans = 0 ;count = 0 ;pro = 1

n,m=map(int,input().split())
data=[[] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1;b-=1
    data[a].append(b)
    data[b].append(a)
def dfs(node,s):
    # print(node,s)
    if len(s)==n:
        global count
        count+=1
    s=s.copy()
    for vi in data[node]:
        if vi not in s:
            dfs(vi,s|{vi})
dfs(0,{0})
print(count)