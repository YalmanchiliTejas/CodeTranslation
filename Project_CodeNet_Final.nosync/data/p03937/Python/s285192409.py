#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1
h,w = map(int,input().split())
A = [list(input()) for i in range(h)]
que = collections.deque()
que.append((0,0))
while que:
  i,j = que.popleft()
  A[i][j] = "."
  if 0 <= i+1 < h:
    if A[i+1][j] == "#":
      que.append((i+1,j))
      continue
  if 0 <= j + 1 < w:
    if A[i][j+1] == "#":
      que.append((i,j+1))
# print(*A,sep="\n")
for i in range(h):
  for j in range(w):
    if A[i][j] == "#":
      print("Impossible")
      exit()
print("Possible")