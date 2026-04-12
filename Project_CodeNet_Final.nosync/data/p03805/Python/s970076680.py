n,m=map(int,input().split())
road=[[] for _ in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    road[a].append(b)
    road[b].append(a)
dp=[[0]*(n+1) for _ in range(2**n)]
dp[1][1]=1
for i in range(1,2**n):
    for j in range(1,n+1):
        for k in road[j]:
            if not (i>>(k-1))&1:
                dp[i+2**(k-1)][k]+=dp[i][j]
print(sum(dp[2**n-1]))

