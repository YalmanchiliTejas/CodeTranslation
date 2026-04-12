# -*- coding: utf-8 -*-
r,g,b =map(str, input().split())
S = r+g+b
T = int(S)
if T % 4 == 0:
  print("YES")
else:
  print("NO")