import itertools
n, m = map(int, input().split())
e = [[] for _ in range(n)]
ans = 0

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    e[u].append(v)
    e[v].append(u)

for route in itertools.permutations(range(1, n), n - 1):

    visited = [False] * n
    visited[0] = True
    route = list(route)
    route.insert(0, 0)
    for i in range(1, n):
        now = route[i - 1]
        nxt = route[i]
        if str(nxt) in str(e[now]) and not(visited[nxt]):
            visited[nxt] = True
            if i == n - 1:
                ans += 1
        else:
            break

print(ans)