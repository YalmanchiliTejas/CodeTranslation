from collections import defaultdict
from itertools import permutations

N, M = map(int, input().split(' '))
graph = defaultdict(set)
for _ in range(M):
    a, b = map(int, input().split(' '))
    graph[a].add(b)
    graph[b].add(a)

count = 0
for path in permutations(range(2, N + 1)):
    if path[0] not in graph[1]:
        continue

    for n1, n2 in zip(path, path[1:]):
        if n2 not in graph[n1]:
            break
    else:
        count += 1

print(count)
