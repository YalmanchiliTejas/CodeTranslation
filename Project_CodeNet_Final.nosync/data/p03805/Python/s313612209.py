# dfsで解く
def dfs(v):
    global adjacency_list, ans, visited
    # 全部訪れたか判定
    if sum(visited) == N:
        ans += 1
        return
    for a in adjacency_list[v]:
        # 訪れたことがあるなら何もしない
        if visited[a] == True:
            continue
        # 訪れたことがないなら
        else:
        # 訪れたことにする
            visited[a] = True
            dfs(a)    
        # 頂点aを未訪問にする
            visited[a] = False

if __name__ == "__main__":
    # input
    N, M = map(int, input().split())
    # 隣接listを作る
    adjacency_list = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        adjacency_list[a-1].append(b-1)
        adjacency_list[b-1].append(a-1)
    # 訪れたかどうか
    visited = [False] * N
    visited[0] = True # 0を訪れたことにする
    ans = 0 # 答え
    dfs(0)
    print(ans)

