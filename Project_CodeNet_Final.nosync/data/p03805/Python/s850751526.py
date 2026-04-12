# n : ノード数
# m : パス数
n, m = map(int, input().split())

# iノード, jノードにパスがある場合はconn[i][j] = conn[j][i] = True
conn = []
for _ in [0]*n:
    conn.append([False]*n)

# iノードに訪れたことがある場合はvisited[i] = True
visited = [False] * n

# グラフ入力
# ノード番号から-1して0始まりにしておく
v = []
for _ in [0]*m:
    line = map(int, input().split())
    v.append([x-1 for x in line])

# connテーブルを初期化
for start, end in v:
    conn[start][end] = conn[end][start] = True


def dfs(now, depth):
    if visited[now]: return 0
    if depth == n - 1: return 1
    
    visited[now] = True
    ret = 0

    for i in range(0, n):
        if conn[now][i]: ret += dfs(i, depth+1)
    
    visited[now] = False

    return ret

print(dfs(0, 0))