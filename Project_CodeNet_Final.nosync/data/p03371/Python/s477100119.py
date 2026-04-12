import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)
INF = float('inf')

from functools import lru_cache

A, B, C, X, Y = map(int, input().split())

# 4通りしかない

# A, Bをそれぞれ買う
ans = A * X + B * Y

# AB + A or B
if X < Y:
    tmp = X * (2 * C)
    tmp += abs(X - Y) * B
else:
    tmp = Y * (2 * C)
    tmp += abs(X - Y) * A
ans = min(ans, tmp)

# AB
ans = min(ans, max(X, Y) * (2 * C))

print(ans)
