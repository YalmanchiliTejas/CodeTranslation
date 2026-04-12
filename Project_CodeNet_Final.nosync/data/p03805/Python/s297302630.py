n,m=map(int,input().split())
if m==0:
    print(0)
    exit()
ans=[[] for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    ans[a-1].append((b-1))
    ans[b-1].append((a-1))
v=[]#全ての点を訪問済み
def dfs(now,visited=[]):
    global v
    if len(visited)==n:
        v.append([visited])
        return
    for j in ans[now]:
        if j not in visited:
            dfs(j,visited+[j])
dfs(0,[0])
print(len(v))
