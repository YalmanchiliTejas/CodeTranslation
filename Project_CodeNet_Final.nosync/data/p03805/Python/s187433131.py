from itertools import permutations
from collections import defaultdict
n, m = map(int, input().split())
routes = permutations(range(2, n+1), n-1)
count = 0

edges = defaultdict(list)

for _ in range(m):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

for route in routes:
    goal = True
    now_node = 1
    for way_index in range(len(route)):
        if not route[way_index] in edges[now_node]:
            goal = False
        now_node = route[way_index]
    if goal:
        count += 1
print(count)