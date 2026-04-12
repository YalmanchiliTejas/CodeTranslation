n,m = map(int,input().split())
l = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    l[a-1].append(b-1)
    l[b-1].append(a-1)
def dfs(i,done):
    ret = 0
    if i in done:
        return 0
    if len(done)==n-1:
        return 1
    for j in range(len(l[i])):
        ret += dfs(l[i][j],done+[i])
    return ret
print(dfs(0,[]))