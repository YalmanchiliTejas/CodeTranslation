#!/usr/bin/env python3
# -*- coding: utf-8 -*-
h,w  = map(int, input().split())
s=[]
for i in range(0,h):
  s.append(input())

b=[]
for i in range(0,w):
  f=False
  for j in range(0,h):
    if s[j][i]=='#':
      f=True
  b.append(f)

for j in range(0,h):
  if s[j].count('#')==0:
    continue
  res=""
  for i in range(0,w):
    if b[i]:
      res=res+s[j][i]
  print(res)


