N, M = map(int,input().split())
G = [[] for k in range(N)]

for k in range(M):
    a, b = map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

def dfs(ima,visited):
    global ans
    visited[ima] = 1
    for tsugi in G[ima]:
        if visited[tsugi] == 0:
            visited[tsugi] = 1
            if sum(visited) == N:
                ans += 1
            dfs(tsugi,visited)
            visited[tsugi] = 0
ans = 0
dfs(0,[0]*N)
print(ans)
