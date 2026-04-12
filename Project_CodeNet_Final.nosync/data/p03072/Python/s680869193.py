# -*- coding: utf-8 -*-
n = int(input())
h = list(map(int, input().split()))

ans = 0
for i in range(n):
  if i == 0:
    ans += 1
  elif (i == 1) and (h[0] <= h[i]):
    ans += 1
  elif (i > 1) and (max(h[:i]) <= h[i]):
    ans += 1

print(ans)
