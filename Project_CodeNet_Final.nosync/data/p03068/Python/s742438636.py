import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n = ni()
s = list(ns())
k = ni()
a = s[k - 1]
for i in range(len(s)):
    if s[i] != a:
        s[i] = '*'
print(''.join(s))
