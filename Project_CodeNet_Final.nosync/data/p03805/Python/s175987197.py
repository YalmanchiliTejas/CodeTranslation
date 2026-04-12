n,m = list(map(int,input().split()))
V=[[] for _ in range(n)]
for _ in range(m):
    a,b=list(map(int,input().split()))
    V[a-1].append(b-1)
    V[b-1].append(a-1)

def solve(path,i,cnt):
    if cnt==n:return 1
    path=list(path)
    path[i]=True
    ans=0
    for v in V[i]:
        if path[v]:continue        
        ans+=solve(tuple(path),v,cnt+1)
    return ans

print(solve([False]*n,0,1))

