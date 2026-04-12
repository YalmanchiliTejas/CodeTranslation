import sys
from collections import Counter
n = int(input())
res = Counter(sys.stdin.readline().strip())
for i in range(n - 1):
    s = sys.stdin.readline().strip()
    ct = Counter(s)
    ls = []
    for k, v in res.items():
        if ct[k] < v:
            ls.append(k)
    for l in ls:
        res[l] = ct[l]
res = "".join([i*j for i, j in res.items()])
print("".join(sorted(res)))