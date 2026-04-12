import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
h = nl()
ans = 0
for i in range(n):
    f = 0
    for j in range(0, i):
        if h[j] > h[i]:
            f = 1
    if f == 0:
        ans += 1
print(ans)
