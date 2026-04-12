import copy
from collections import Counter
n = int(input())
S = [input() for i in range(n)]
c1 = Counter(S[0])
for i in range(n):
    c2 = Counter(S[i])
    common_keys = c1.keys() & c2.keys()
    c3 = {}
    for key in common_keys:
        c3[key] = min(c1[key], c2[key])
    c1 = copy.deepcopy(c3)

ans = ""
for key, val in sorted(c1.items(), key=lambda x:x[0]):
    ans = ans + key * val
print(ans)