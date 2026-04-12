from copy import copy
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    G[b - 1].append(a - 1)
    G[a - 1].append(b - 1)

ans = 0
st = [[0, [False] * N]]
while len(st) > 0:
    _st = st.pop()
    v = _st[0]
    visited = copy(_st[1])
    if visited[v]:
        continue
    visited[v] = True
    adj_all_visit = True
    for adj in G[v]:
        if visited[adj]:
            continue
        st.append([adj, visited])
        adj_all_visit = False
    if adj_all_visit and all(visited):
        ans += 1
print(ans)
