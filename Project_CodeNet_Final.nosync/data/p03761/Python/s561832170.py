from collections import Counter
from functools import reduce
from operator import and_
n, *S = open(0).read().split()
keys = reduce(and_, map(set, S))
d = {c:10**6 for c in keys}
for counter in map(Counter, S):
    for c in keys:
        if c in counter:
            d[c] = min(d[c], counter[c])
ans = ''
for k, v in sorted(d.items()):
    ans += k * v
print(ans)