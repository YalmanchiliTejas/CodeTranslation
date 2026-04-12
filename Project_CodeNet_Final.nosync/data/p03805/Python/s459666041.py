N, M = map(int, input().split())

to = [[] for _ in range(N)]
visited = [False] * N

def dfs(v):
    if sum(visited) == N:
        return 1 
    
    ret = 0
    for u in to[v]:
        if not visited[u]:
            visited[u] = True
            ret += dfs(u)
            visited[u] = False  # 最も深い点から帰ってくる道中に、始点を除く全ての点を未訪問にする => 他のパスを辿ることが可能になる

    return ret


for _ in range(M):
    a, b = map(int, input().split())
    to[a-1].append(b-1)
    to[b-1].append(a-1)

visited[0] = True
print(dfs(0))