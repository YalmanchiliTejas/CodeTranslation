N, M = map(int, input().split())

# 隣接リスト
# node iとつながってるnodeはnei_L[i - 1]に入ってる
nei_L = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    nei_L[a - 1].append(b - 1)
    nei_L[b - 1].append(a - 1)

ans = 0
visited = [0] * N

def dfs(now=0):
    global visited, ans
    visited[now] = 1
    if all(visited):
        ans += 1
        # visited = [0] * N
    else:
        cand = nei_L[now]
        for c in cand:
            if not visited[c]:
                dfs(c)
    visited[now] = 0

dfs()
print(ans)
