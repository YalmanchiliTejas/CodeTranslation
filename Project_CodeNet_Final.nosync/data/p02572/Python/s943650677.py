import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

n = ni()
a = na()
mod = 1000000007

s = sum(a)
s2 = 0
for u in a:
    s2 += u*u
print((s*s - s2) // 2 % mod)
