# -*- coding: utf-8 -*-

# 整数の入力
N = int(input())
S = str(input())
K = int(input())

for i in range(N):
  if S[i]!=S[K-1]:
    print("*",end="")
  else:
    print(S[i],end="")