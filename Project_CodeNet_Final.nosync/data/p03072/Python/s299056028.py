# -*- coding: utf-8 -*-

N = int(input())
H = list(map(int, input().split()))

ans = 0
highest = 0
for i in range(N):
    if H[i] >= highest:
        ans += 1
        highest = H[i]

print(ans)
