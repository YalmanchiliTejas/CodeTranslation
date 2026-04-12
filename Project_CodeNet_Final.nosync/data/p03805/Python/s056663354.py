N, M = list(map(int, input().split()))
edge = [[0] * N for i in range(N)] # 辺を行列で表す
for i in range(M):
    a, b = list(map(int, input().split()))
    edge[a-1][b-1] = 1
    edge[b-1][a-1] = 1

def dfs(v, n, visited):
    all_visited = True

    for i in range(N):
        if visited[i] == False:
            all_visited = False

    if all_visited == True:
        return 1

    ret = 0

    for i in range(N):
        if edge[v][i] == 0: # 繋がってない
            continue
        if visited[i]: # 訪問済み
            continue

        visited[i] = True
        ret += dfs(i, N, visited)
        visited[i] = False

    return ret

# 訪問したかどうかのフラグ（最初はFalse）
visited = [False] * N

visited[0] = True
re = dfs(0, N, visited)
print(re)