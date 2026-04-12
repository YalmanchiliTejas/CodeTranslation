# -*- coding: utf-8 -*-
 
import math
import itertools
import sys
import copy
 
# 入力
#A, B, C, D = map(int, input().split())
#L = list(map(int, input().split()))
#S = list(str(input()))
#H = int(input())
H, W = map(int, input().split())
A = []
for _ in range(H) :
  A.append(list(str(input())))
#print (A)

for i in range(H) :
  wcnt = 0
  for j in range(W) :
    if A[i][j] == "." :
      wcnt += 1
  if wcnt == W :
    for j in range(W) :
      A[i][j] = "0"
#print (A)

for j in range(W) :
  wcnt = 0
  for i in range(H) :
    if A[i][j] == "." or A[i][j] == "0":
      wcnt += 1
  if wcnt == H :
    for i in range(H) :
      A[i][j] = "0"
#print (A)

for i in range(H) :
  ans = ""
  for j in range(W) :
    if A[i][j] != "0" :
      ans += A[i][j]
  if ans != "" :
    print (ans)
