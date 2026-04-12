#!/usr/bin/env python3
import sys, math, itertools, heapq, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
sys.setrecursionlimit(10**8)
inf = float('inf')
ans = 0
count = 0
n=int(input())
A=[int(input()) for i in range(n)]
A.sort()
if n%2==1:
    if A[n//2]-A[n//2-1]<=A[n//2+1]-A[n//2]:
        A.insert(0,A[n//2+1])
    else:
        A.append(A[n//2])
    n+=1
tmp=A[n//2]
for i in range(n//2):
    ans+=abs(tmp-A[i+n//2])
    tmp = A[i+n//2]
    # print(tmp)
    ans+=abs(tmp-A[i])
    tmp=A[i]
    # print(tmp)
print(ans)

# print(A)