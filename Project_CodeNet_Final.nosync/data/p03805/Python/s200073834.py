import itertools

N, M = [int(s) for s in input().split()]

edge = [[int(s) - 1 for s in input().split()] for _ in range(M)]
graph = [[] for _ in range(N)]
for i, j in edge:
    graph[i].append(j)
    graph[j].append(i)

result = 0
for path in itertools.permutations(range(1, N)):
    cnt = 0
    for p1, p2 in zip([0] + list(path[:-1]), list(path)):
        cnt += p2 in graph[p1]
    result += cnt == (N - 1)

print(result)
