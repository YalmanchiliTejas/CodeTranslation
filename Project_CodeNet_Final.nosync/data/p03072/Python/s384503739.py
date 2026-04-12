#!/usr/bin/env python3
n, *h = map(int, open(0).read().split())
m = h[0]
for i in range(n):
    if m > h[i]:
        n -= 1
    m = max(m, h[i])
print(n)