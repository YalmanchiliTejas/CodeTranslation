#!/usr/bin/env python3
import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 7)

A,B,C,X,Y = map(int,readline().split())
L = []
L.append(A*X+B*Y)
for i in range(1, min(X,Y)+1):
    sum = A*(X-i)+B*(Y-i)+C*2*i
    L.append(sum)
ans = min(L)
if max(X,Y)*2*C<ans:
    ans = max(X,Y)*2*C
print(ans)