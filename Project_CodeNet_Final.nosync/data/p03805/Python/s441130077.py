n, m = [int(x) for x in input().split()] # n: 頂点, m: 辺
line = [ tuple( int(x)-1 for x in input().split() ) for _ in range(m) ]

matrix = [ [False]*n for _ in range(n) ] # n x n 行列
for a, b in line:
    matrix[a][b] = True
    matrix[b][a] = True

visited = [False]*n

def dfs(point, depth):
    if visited[point]:
        return 0

    if depth == n - 1:
        return 1

    visited[point] = True
    total = 0
    for i, np in enumerate(matrix[point]):
        if np:
            total += dfs(i, depth + 1)

    visited[point] = False
    return total

print(dfs(0, 0))
