n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]

from collections import defaultdict
graph = defaultdict(list)
for i in range(m):
    a = ab[i][0] - 1
    b = ab[i][1] - 1
    graph[a].append(b)
    graph[b].append(a)

ans = 0
import itertools
for orders in itertools.permutations(list(range(n))):
    if orders[0] != 0:
        continue

    # check
    f = True
    for j in range(len(orders) - 1):
        if orders[j+1] not in graph[orders[j]]:
            f = False
    if f:
        ans += 1
        # print(orders)

print(ans)
