#!/usr/bin/env python3

a, b, c, x, y = map(int, input().split())

ans = 2*5000*100000
for k in range(100001):
    tmp = 2*c*k + max(x-k, 0)*a + max(y-k, 0)*b
    ans = min(ans, tmp)
print(ans)
