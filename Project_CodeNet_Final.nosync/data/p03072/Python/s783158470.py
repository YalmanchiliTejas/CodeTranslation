# -*- coding: utf-8 -*-
n = int(input())
h = list(map(int, input().split()))

ans = 0
for i in range(n):
  ans += 1 if (i == 0) or ((i == 1) and (h[0] <= h[i])) or ((i > 1) and (max(h[:i]) <= h[i])) else 0

print(ans)