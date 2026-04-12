  # -*- coding: utf-8 -*-
N = int(input())
S = str(input())
K = int(input())

Sk = S[K-1]
a = []

for i,char in enumerate(S):
  if char != Sk:
    a.append(str('*'))
  else:
    a.append(char)

print(''.join(a))