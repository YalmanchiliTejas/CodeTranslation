import copy
import collections

n = int(input())
k = list(input())
t = collections.Counter(k)
d = {i:t[i] for i in t.keys()}

for _ in range(n - 1):
    k = list(input())
    t = collections.Counter(k)
    for key, value in t.items():
        if key in d.keys():
            d[key] = min(value, d[key])
    j = copy.deepcopy(list(d.keys()))
    for key in j:
        if key not in t.keys():
            del d[key]
ans = ""
for k in sorted(list(d.keys())):
    ans = ans + k * d[k]
print(ans)