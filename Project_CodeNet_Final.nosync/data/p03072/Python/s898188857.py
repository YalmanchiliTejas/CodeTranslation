# -*- coding: utf-8 -*-
 
import math
import itertools
import sys
import copy
 
# 入力
#A, B, C, D = map(int, input().split())
#L = list(map(int, input().split()))
#S = list(str(input()))
#N = int(input())
#S = str(input())
N = int(input())
H = list(map(int, input().split()))

cnt = 1
hmax = H[0]
for i in range(1, N) :
  if hmax <= H[i] :
    cnt += 1
    hmax = H[i]
print (cnt)


