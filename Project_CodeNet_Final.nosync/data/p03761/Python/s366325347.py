#!/usr/bin/env python3
from collections import Counter

n, *s = open(0).read().split()
c = Counter(s[0])
for i in s[1:]:
    for j in c.keys():
        c[j] = min(c[j], i.count(j))
print(*sorted(i * j for i, j in c.items()), sep="")
