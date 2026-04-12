from collections import defaultdict
from copy import deepcopy

n = int(input())
dd = defaultdict(int)
for i in range(n):
    s = input()
    d = defaultdict(int)
    for j in s:
        d[j] += 1
    if i == 0:
        dd = deepcopy(d)
    else:
        for j in dd.keys():
            dd[j] = min(dd[j], d[j])

print("".join(
    sorted(
        [(i * dd[i] if dd[i] != 0 else "") for i in dd.keys()]
        )
))
