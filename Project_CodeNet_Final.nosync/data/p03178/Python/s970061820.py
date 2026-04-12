mod=10**9+7
K=list(map(int,input().strip()))
d=int(input())
l=len(K)
DP=[[[0]*d for _ in range(2)] for _ in range(l+1)]
DP[0][0][0]=1
for i,k in enumerate(K):
    for less in range(2):
        if less:
            limit=9
        else:
            limit=k
        for m in range(d):
            for l in range(limit+1):
                DP[i+1][less or l<limit][(m+l)%d]+=DP[i][less][m]
                DP[i+1][less or l<limit][(m+l)%d]%=mod
print((DP[-1][0][0]+DP[-1][1][0]-1)%mod)