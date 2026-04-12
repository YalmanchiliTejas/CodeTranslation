import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

N, X = nm()
s = [1]
p = [1]
for i in range(N):
    s.append(s[i] * 2 + 3)
    p.append(p[i] * 2 + 1)


def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    if x <= s[n - 1] + 1:
        return f(n - 1, x - 1)
    else:
        return p[n - 1] + f(n - 1, x - s[n - 1] - 2) + 1

print(f(N, X))
