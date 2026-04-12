n,m=map(int,input().split())
g=[[] for _ in range(n)]
cnt=[0]
for _ in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
def dfs(z,s):
    if sum(z)==n:
        cnt[0]+=1
    else:
        for i in g[s]:    
            if z[i]==0:
                dfs(z[:i]+[1]+z[i+1:],i)

dfs([1]+[0]*(n-1),0)
print(*cnt)