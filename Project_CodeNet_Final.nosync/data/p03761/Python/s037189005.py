import sys
from collections import defaultdict

def f(s):
    d = defaultdict(int)
    for c in s:
        d[c] += 1
    return d

def g(d1, d2):
    new_d = {}
    ks = set(d1.keys()).intersection(set(d2.keys()))
    for k in ks:
        new_d[k] = min(d1[k], d2[k])
    return new_d

sys.stdin.readline()
d2 = None
for line in sys.stdin.readlines():
    d = f(line.strip())
    if d2 is None:
        d2 = d
    else:
        d2 = g(d, d2)
for c in sorted(d2.keys()):
    print(c * d2[c], end='')
print()
