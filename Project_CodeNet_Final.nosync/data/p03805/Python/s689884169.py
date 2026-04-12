#dfs(再帰)
import sys
sys.setrecursionlimit(1000000000)

N, M = map(int, input().split())
a, b = [0]*M, [0]*M
for i in range(M):
    a[i], b[i] = map(int, input().split())

c = [[0]*N for _ in range(N)]
for x, y in zip(a, b):
    c[x-1][y-1] = 1
    c[y-1][x-1] = 1
visited = [-1]*N
visited[0] = 1
ans = 0

def dfs(n):
    global ans
    if sum(visited) == N:
        ans += 1
        return
    else:
        for i, x in enumerate(c[n]):
            if x == 1 and visited[i] == -1:
                visited[i] = 1
                dfs(i)
                visited[i] = -1
    return

dfs(0)
print(ans)