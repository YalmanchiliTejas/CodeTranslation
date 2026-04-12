import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)
INF = float('inf')

from functools import lru_cache

A, B, C, X, Y = map(int, input().split())

ans = INF
for i in range((10**5)+1):
    tmp = i * 2 * C
    if X - i > 0:
        tmp += (X - i) * A
    if Y - i > 0:
        tmp += (Y - i) * B
    ans = min(ans, tmp)
print(ans)