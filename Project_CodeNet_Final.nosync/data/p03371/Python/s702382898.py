import sys
stdin = sys.stdin

mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))

A, B, C, X, Y = na()
ans = 10**10
for ab in range((10**5+1)*2):
    cost = ab * C
    cost += max(0, X - ab//2) * A
    cost += max(0, Y - ab//2) * B
    ans = min(ans, cost)
print(ans)
