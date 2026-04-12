import bisect
import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

n = ni()
a = []
for i in range(n):
    a.append(ni())
a = a[::-1]
hs = [999999999999] * (n+1)
lis = 0
for v in a:
    pos = bisect.bisect_right(hs, v)
    hs[pos] = v
    lis = max(lis, pos+1)
print(lis)
