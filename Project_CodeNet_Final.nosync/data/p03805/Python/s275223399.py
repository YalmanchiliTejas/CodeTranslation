import sys
sys.setrecursionlimit(10**9)
N,M = map(int,input().split())
note = [[0]*N for i in range(N)]
visited = [False]*N
visited[0] = True
ans = 0
for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    note[a][b] = 1
    note[b][a] = 1

def dfs(p=0, depth=0):
    if depth == N-1:
        global ans
        ans += 1
        return
    for i in range(N):
        if note[p][i] == 1 and visited[i] is False:
            visited[i] = True
            dfs(i,depth+1)
            visited[i] = False

dfs()
print(ans)