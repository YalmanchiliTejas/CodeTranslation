N, M = map(int, input().split())
P = [list(map(int, input().split())) for k in range(M)]
G = [[0 for k in range(N)] for k in range(N)]
for p in P:
    G[p[0]-1][p[1]-1] = G[p[1]-1][p[0]-1] = 1

def dfs(ima,itta):
    if len(itta)==N:
        return 1
    ans = 0
    for k in range(N):
        if ima[k]==1 and k not in itta:
            itta.append(k)
            ans += dfs(G[k],itta)
            itta.remove(k)
    return ans

print(dfs(G[0],[0]))
