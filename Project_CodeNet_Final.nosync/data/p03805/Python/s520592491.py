n,m = map(int,input().split())
g = [[] for _ in range(0,n)]
for i in range(0,m):
    a,b = map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

ans = 0
global visit
visit = [1 for i in range(0,n)]

def dfs(s):
    if sum(visit) == 0:
        global ans
        ans += 1
        return
    for i in g[s]:
        # print(ans,visit)
        if visit[i] == 1:
            visit[i] = 0
            dfs(i)
            visit[i] = 1
    return

visit[0] = 0
dfs(0)
print(ans)
