n, m = map(int, input().split())
conn = [[False]*n for _ in range(n)]
visited = [False] * n
v = []
for _ in range(m):
    i, j = map(int, input().split())
    v.append([i-1, j-1])

for s, e in v:
    conn[s][e] = conn[e][s] = True
def search(now, depth):
    if visited[now] is True:
        return 0
    if depth == n-1:
        return 1
    visited[now] = True
    ret = 0
    for i in range(n):
        if conn[now][i] is True:
            ret += search(i, depth+1)
    visited[now] = False
    return ret

print(search(0, 0))