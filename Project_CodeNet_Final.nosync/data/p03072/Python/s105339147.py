#!/usr/bin/env python3
n = int(input()) 
l = list(map(int, input().split()))
ans = 1
for i in range(1, n):
    if max(l[:i]) <= l[i]:
        ans += 1
print(ans)