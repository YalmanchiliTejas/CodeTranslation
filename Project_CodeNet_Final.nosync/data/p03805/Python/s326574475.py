def dfs(curr, visit_state, adj_list, count, num_vertex):
    if count == num_vertex:
        return 1
    if all(visit_state[i] for i in adj_list[curr]) and count != num_vertex:
        return 0
    result = 0
    for nb in adj_list[curr]:
        if not visit_state[nb]:
            visit_state[nb] = True
            result += dfs(nb, visit_state, adj_list, count + 1, num_vertex)
            visit_state[nb] = False
    return result


n, m = map(int, input().split())
adj = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)
visited = [False] * n
visited[0] = True
print(dfs(0, visited, adj, 1, n))
