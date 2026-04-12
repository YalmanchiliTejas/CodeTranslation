# dfsで解く
def dfs_mat(v):
    global adjacency_mat, ans, visited
    # 全部訪れたか判定
    if sum(visited) == N:
        ans += 1
        return
    for i in range(N):
        if adjacency_mat[v][i]:
            # 訪れたことがあるなら何もしない
            if visited[i] == True:
                continue
            # 訪れたことがないなら
            else:
            # 訪れたことにする
                visited[i] = True
                dfs_mat(i)    
            # 頂点aを未訪問にする
                visited[i] = False


if __name__ == "__main__":
    # input
    N, M = map(int, input().split())
    # 隣接行列を作る
    adjacency_mat = [[None]* N for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        adjacency_mat[a-1][b-1] = 1
        adjacency_mat[b-1][a-1] = 1
    # 訪れたかどうか
    visited = [False] * N
    visited[0] = True # 0を訪れたことにする
    ans = 0 # 答え
    dfs_mat(0)
    print(ans)


