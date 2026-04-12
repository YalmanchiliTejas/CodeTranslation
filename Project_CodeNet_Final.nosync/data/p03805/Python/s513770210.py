num_ver, num_edge = map(int,input().split())
# 隣接行列
graph_mat = [[0]*num_ver for _ in range(num_ver)]

for i in range(num_edge):
    start, goal = map(int,input().split())
    start -= 1
    goal -= 1
    graph_mat[start][goal] = 1
    graph_mat[goal][start] = 1

visited = [0] * num_ver

def dfs(now, depth):
    if visited[now]:
        return 0
    if depth == num_ver - 1:
        return 1
    
    visited[now] = 1
    num_path = 0

    for ver in range(num_ver):
        if graph_mat[now][ver]:
            num_path += dfs(ver, depth + 1)
    
    # 別の一筆書きの道として探索されることを考慮、もちろん頂点1についてはこれは意味ない
    visited[now] = 0

    return num_path
print(dfs(0,0))