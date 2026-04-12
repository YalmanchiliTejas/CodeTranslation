def dfs(visited, s):
    visited = visited[:]  # このような渡し方をすることで、もしそのルートが不正解だった時に分岐まで戻ることができる
    global ans
    visited[s] = True
    for t in graph[s]:  # startとtarget
        if not visited[t]:  # 未訪問なら
            dfs(visited, t)

    # 自身から伸びているノードが全て訪問済みなら以下の処理をする
    if all(visited):
        ans += 1


N, M = map(int, input().split())

graph = [[] for _ in range(N)]
visited = [False]*N

for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    graph[a].append(b)
    graph[b].append(a)

ans = 0
dfs(visited, 0)

print(ans)
