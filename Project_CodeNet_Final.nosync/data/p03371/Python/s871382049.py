import sys
import itertools

# import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

A, B, C, X, Y = map(int, readline().split())
ans = 0
if A + B > 2 * C:
    if X > Y:
        ans += Y * C * 2
        ans += (X - Y) * A
    else:
        ans += X * C * 2
        ans += (Y - X) * B
else:
    ans += A * X + B * Y
print(min(ans, C * 2 * max(X, Y)))
