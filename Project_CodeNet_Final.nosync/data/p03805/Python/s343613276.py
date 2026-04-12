N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

ans = 0
def dfs(cur, rem):
    global ans
    if len(rem) == 0:
        ans += 1
        return
    for cand in G[cur]:
        if cand in rem:
            i = rem.index(cand)
            dfs(cand, rem[:i] + rem[i+1:])

dfs(0, list(range(1, N)))

print(ans)

