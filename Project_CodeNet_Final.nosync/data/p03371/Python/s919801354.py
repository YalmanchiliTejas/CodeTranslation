#!/usr/bin/env python3
a, b, c, x, y = map(int, input().split())
print(
    min(
        a * x + b * y,
        max(x, y) * c * 2,
        c * x * 2 + (y - x) * b if y > x else c * y * 2 + (x - y) * a if x > y else 10**9,
    ))
