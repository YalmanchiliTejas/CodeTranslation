import sys
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
g = [[]*n for _ in range(n)]
for _ in range(m):
    a, b = [int(x) for x in input().split()]
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)
v = [int(x) for x in range(n)]
from itertools import permutations
v_per = list(permutations(v, n))
ans = 0
for per in v_per:
    if per[0] != 0:
        continue
    flag = 1
    for i in range(len(per) - 1):
        if per[i + 1] not in g[per[i]]:
            flag = 0
            break
    if flag:
        ans += 1
print(ans)