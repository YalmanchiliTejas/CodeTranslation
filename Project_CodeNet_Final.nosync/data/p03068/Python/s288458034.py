# -*- coding: utf-8 -*-
 
import math
import itertools
import sys
import copy
 
# 入力
#A, B, C, D = map(int, input().split())
#L = list(map(int, input().split()))
#S = list(str(input()))
N = int(input())
S = str(input())
K = int(input())

c = S[K-1]
ans = ""
for i in range(N) :
  if S[i] == c :
    ans += c
  else :
    ans += "*"
    
print (ans)



