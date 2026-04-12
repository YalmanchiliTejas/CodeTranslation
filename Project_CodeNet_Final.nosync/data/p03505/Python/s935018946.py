#!/usr/bin/env python3
def solve(k, a, b):
    if a - b <= 0:
        if k <= a:
            return 1
        else:
            return -1
    return 1 + (k - a + (a - b) - 1) // (a - b) * 2
k, a, b = map(int, input().split())
print(solve(k, a, b))
