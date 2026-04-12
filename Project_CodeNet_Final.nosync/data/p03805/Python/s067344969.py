n, m = map(int, input().split())

from collections import defaultdict
d = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    d[a].append(b)
    d[b].append(a)

from itertools import permutations
C = permutations(range(2, n+1))
C = list(map(lambda x: [1]+list(x), C))

ans = 0
for c in C:
    for i in range(n-1):
        if c[i+1] not in d[c[i]]:
            break
    else:
        ans += 1
print(ans)