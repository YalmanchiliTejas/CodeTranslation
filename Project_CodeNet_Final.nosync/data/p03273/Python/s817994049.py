# -*- coding: utf-8 -*-
import re
H, W = map(int, input().split())
l = []
for i in range(H):
  a = input()
  if(len(re.findall('#', a)) != 0):
    l.append(a)
#print(l)

hh = len(l)
l2 = []
for j in range(W):
  if(l[0][j] == '.'):
    flag = 0
    for k in range(hh):
      if(l[k][j] == '#'):
        flag = 1
    if(flag == 0):
      l2.append(j)
#print(l2)

l3 = list(range(W))
#print(l3)
l4 = list(set(l3) - set(l2))
#print(l4)

for k in range(hh):
  a = ''
  for ll in l4:
   #print(l[k][ll]) 
   a = a + l[k][ll]
  print(a)
