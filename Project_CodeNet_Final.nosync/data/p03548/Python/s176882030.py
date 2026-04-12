# -*- coding: utf-8 -*-
X,Y,Z = map(int,input().split())
a = []
X = X-Z
while X >= Z+Y:
  a.append(1)
  X = X - (Z+Y)
print(sum(a))