n,m=map(int,raw_input().split())
g=[[] for _ in xrange(n)]
for i in xrange(m):
    a,b=map(int,raw_input().split())
    a-=1;b-=1
    g[a].append(b)
    g[b].append(a)
dp=[[0]*(1<<n) for _ in xrange(n)]
dp[0][1]=1
for j in xrange(1<<n):
    for i in xrange(n):
        if j>>i&1:
            for k in g[i]:
                if j>>k&1:
                    continue
                dp[k][j|(1<<k)]+=dp[i][j]
ans=0
for i in xrange(1,n):
    ans+=dp[i][(1<<n)-1]
print(ans)