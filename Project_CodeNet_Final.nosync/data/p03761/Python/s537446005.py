import sys
import collections

rr = lambda: sys.stdin.readline().rstrip()
rs = lambda: sys.stdin.readline().split()
ri = lambda: int(sys.stdin.readline())
rm = lambda: map(int, sys.stdin.readline().split())
rl = lambda: list(map(int, sys.stdin.readline().split()))

n = ri()
d = collections.Counter(rr())
for _ in range(n-1):
    d1 = collections.Counter(rr())
    h = dict()
    for k, v in d1.items():
        if k in d:
            h[k] = min(d[k], v)
    d = h
s = ''
for k in sorted(d):
    s += k*d[k]
print(s)    











