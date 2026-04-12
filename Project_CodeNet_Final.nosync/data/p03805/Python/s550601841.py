nmax = 8
graph = [[False for i in range(nmax)] for j in range(nmax)]

def dfs(v, N, visited):
    all_visited = True

    for i in range(N):
        if visited[i] == False:
            all_visited = False

    if all_visited:
        return 1

    ret = 0

    for i in range(N):
        if graph[v][i] == False:
            # 経路がない
            continue
        if visited[i] == True:
            # 使用済み
            continue

        visited[i] = True
        ret += dfs(i, N, visited)
        visited[i] = False

    return ret

if __name__ == '__main__':
    n, m = map(int, input().split())

    for i in range(m):
        a, b = map(int, input().split())
        graph[a - 1][b - 1] = True
        graph[b - 1][a - 1] = True

    visited = [False for i in range(n)]

    visited[0] = True
    print(dfs(0, n, visited))
