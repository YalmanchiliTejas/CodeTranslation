N, M = map(int, input().split())
E = [[] for _ in range(N)]
for m in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    E[a].append(b)
    E[b].append(a)

check = [False] * N
check[0] = True
def dfs(v):
    if sum(check) == N:
        return 1
    ans = 0
    for u in E[v]:
        if check[u]:
            continue
        check[u] = True
        ans += dfs(u)
        check[u] = False
    return ans
print(dfs(0))
