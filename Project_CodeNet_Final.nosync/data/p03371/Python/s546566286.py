#!/usr/bin/env python3
a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
for i in range(1, max(x, y) + 1):
    d = a * max(0, (x - i)) + b * max(0, (y - i)) + (c * 2) * i
    ans = min(ans, d)
print(ans)