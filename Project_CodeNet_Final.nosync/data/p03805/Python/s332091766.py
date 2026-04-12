n, m = map(int, input().split())
g = [set() for _ in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    g[a].add(b)
    g[b].add(a)
#print(g)

import itertools
ans = 0
for per in itertools.permutations(range(n)):
    if per[0] != 0:
        continue
    for i in range(n-1):
        if per[i+1]  not in g[per[i]]:
            break
    else:
        ans += 1
print(ans)