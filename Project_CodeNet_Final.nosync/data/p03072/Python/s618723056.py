# import numpy as np

N = int(input())
Hs = list(map(int, input().split()))

ans = 0
max_H = 0
for i in range(N):
  if max_H <= Hs[i]:
    ans += 1
    max_H = max(max_H, Hs[i])

print(ans)