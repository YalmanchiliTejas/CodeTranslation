v=[]
n,m=map(int,input().split())
ans=[[] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    ans[a-1].append((b-1))
    ans[b-1].append((a-1))
def dfs(now,visited=[]):
    if len(visited)==n:
        v.append([visited])
        return
    for j in ans[now]:
        if j not in visited:
            dfs(j,visited+[j])
dfs(0,[0])
print(len(v))
