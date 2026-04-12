#!/usr/bin/env python3
n = int(input())
h = list(map(int, input().split()))
ans = 0
for i in range(n):
    ans += h[i] >= max(h[:i+1])
print(ans)
