from copy import deepcopy

n, m = list(map(int, input().split()))

edges = {}
for i in range(m):
    a, b = list(map(int, input().split()))
    if not a in edges.keys():
        edges[a] = [b]
    else:
        edges[a].append(b)
    if not b in edges.keys():
        edges[b] = [a]
    else:
        edges[b].append(a)

ans = 0

nodes = edges[1]
visited = [1] + [0]*(n-1)
nodes_visited = [(node, visited) for node in nodes]
while len(nodes_visited) > 0:

    # print(nodes_visited)
    node, vstd = nodes_visited[0]
    vstd = deepcopy(vstd)
    nodes_visited = nodes_visited[1:]

    vstd[node-1] = 1
    if min(vstd) > 0:
        ans += 1
        continue

    for node_next in edges[node]:
        if vstd[node_next-1] == 1:
            continue
        else:
            nodes_visited.append((node_next, vstd))

print(ans)