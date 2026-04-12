import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()

n = ni()
h = na()

c = 1
maxh = h[0]
for i in range(n-1):
    if maxh <= h[i+1]:
        c += 1
        maxh = h[i+1]

print(c)
