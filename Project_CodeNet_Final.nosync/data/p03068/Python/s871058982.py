# -*- coding: utf-8 -*-
N = int(input())
S = input()
K = int(input())

t = S[K-1]
tl = set(list(S))
ans = S
for n in tl:
  if n != t:
    ans = ans.replace(n, "*")
print(ans)
