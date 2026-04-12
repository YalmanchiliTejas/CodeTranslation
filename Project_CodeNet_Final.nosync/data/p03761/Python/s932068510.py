import string
# -*- coding: utf-8 -*-
# 整数の入力
n=int(input())
S=[]
for i in range (0,n):
  S.append(input())

count=0
ans=""
for c in range(97,97+26):
  a=S[0].count(chr(c))
  for i in range(0,n):
    a=min(a,S[i].count(chr(c)))
  for i in range (0,a):
    ans+=chr(c)
print(ans)
