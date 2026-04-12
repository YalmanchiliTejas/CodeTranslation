# -*- coding: utf-8 -*-
 
import math
import itertools
import sys
import copy
 
# 入力
#A, B, C, D = map(int, input().split())
#L = list(map(int, input().split()))
#N = int(input())
X, Y, Z = map(int, input().split())

X = X - (Z*2)
cnt = 0
while (X >= Y) :
  X -= Y
  cnt += 1
  X -= Z
  
print (cnt)