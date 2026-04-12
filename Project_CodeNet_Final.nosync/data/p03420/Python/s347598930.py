#!/usr/bin/env python3
n, k = map(int, input().split())
cnt = 0
for b in range(k + 1, n + 1):
    cnt += n // b * (b - k)
    cnt += max(0, min(n % b, n % b - k + 1))
print(cnt)
