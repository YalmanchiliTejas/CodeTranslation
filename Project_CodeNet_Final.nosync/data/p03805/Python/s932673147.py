N,M=map(int,input().split())
Adj = [[0]*N for i in range(1 << N)]
for i in range(M):
    a,b=map(int,input().split())
    Adj[a-1][b-1]=1
    Adj[b-1][a-1]=1


dp = [[0]*N for i in range(1 << N)]
dp[1][0]=1

for S in range(1 << N):
    for v in range(N):
        # if not v in S:
        if S & (1<<v) == 0:
            continue
        
        # sub = S - {v}
        sub = S ^ (1 << v)

        for u in range(N):
            # if u in sub and Adj[u][v] == 1:
            if (1 << u) & sub and Adj[u][v] :
                dp[S][v]+=dp[sub][u]

ans = sum(dp[(1<<N)-1][u] for u in range(1,N))

print(ans)
