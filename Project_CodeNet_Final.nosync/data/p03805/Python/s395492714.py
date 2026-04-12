import itertools

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)
nodes = [i for i in range(N)]
count = 0
for node_order in itertools.permutations(nodes, N):
    if node_order[0] != 0:
        break
    for i in range(N-1):
        if not node_order[i+1] in graph[node_order[i]]:
            break
    else:
        count += 1
print(count)