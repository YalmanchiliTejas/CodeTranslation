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


#再帰関数
def dfs(now, depth):
    if visited[now]:
        return 0
    if depth == num_ver - 1:
        return 1

    visited[now] = 1
    total_paths = 0
    # 「同じ深さの処理」＝場合わけ
    for i in range(num_ver):
        if graph_mat[now][i]:
            total_paths += dfs(i, depth + 1)

    visited[now] = 0

    return total_paths

print(dfs(0, 0))


