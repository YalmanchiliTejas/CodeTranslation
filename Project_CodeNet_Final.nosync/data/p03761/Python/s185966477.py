N = int(input())
S = [input() for _ in range(N)]

import collections
t = [collections.Counter(s) for s in S]

def com(x, y):
    result = {}
    for k,v in x.items():
        if k in y:
            result[k] = min(y[k], v)
    return result

c = t[0]
for x in t[1:]:
    c = com(c, x)

ans = ""
for k in sorted(c.keys()):
    ans += k * c[k]
print(ans)