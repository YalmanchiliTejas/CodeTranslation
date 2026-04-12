from collections import defaultdict
from collections import Counter

n = int(input())
d = defaultdict(int)
S = list(input())
for s in S:
    d[s] += 1

for _ in range(n - 1):
    c = Counter(list(input()))
    for key, values in d.items():
        c_value = c.get(key, 0)
        d[key] = min(d[key], c_value)
# print(d)
d = dict(d)
new_S = []
for key, value in d.items():
    new_S += [key] * value
new_S = sorted(new_S)
# print(new_S)
ans = ''.join(new_S)
print(ans)
