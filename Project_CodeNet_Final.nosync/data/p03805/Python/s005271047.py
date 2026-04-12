from collections import defaultdict
from itertools import permutations

n, m = map(int, input().split())

graph = defaultdict(list)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

pattern = [x for x in permutations(range(1, n + 1)) if x[0] == 1]

ans = []
for p in pattern:
    tmp = []
    for i in range(n - 1):
        if p[i + 1] in graph[p[i]]:
            tmp.append(True)
        else:
            tmp.append(False)
    ans.append(all(tmp))

print(sum(ans))