import itertools

n, m = map(int, input().split())
road = [[0] * n for i in range(n)]

graph = [[] for i in range(n)]
for j in range(m):
    x, y = map(int, input().split())
    road[x - 1][y - 1] += 1
    road[y - 1][x - 1] += 1
    graph[x - 1].append(y - 1)
    graph[y - 1].append(x - 1)
# print(road)
# print(graph)

count = 0

for can in itertools.permutations(range(n)):
    if can[0] != 0:
        break
    # print(can)
    plus = 1
    for k in range(n - 1):
        # print(road[can[k]][can[k + 1]])
        plus *= road[can[k]][can[k + 1]]
    count += plus


def dfs(node, prev, visited):
    visited.append(node)
    if len(visited) == n:
        return 1

    res = 0
    for edge in graph[node]:
        if edge == prev:
            continue
        if edge in visited:
            continue
        res += dfs(edge, prev, visited[:])

    return res


dfs = dfs(0, -1, [])

if count == dfs:
    print(dfs)
