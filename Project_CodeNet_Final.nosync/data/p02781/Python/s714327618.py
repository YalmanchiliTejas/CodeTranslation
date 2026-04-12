s=input()
K=int(input())
n=len(s)
dp=[[[0]*2 for _ in range(K+1)] for _ in range(n+1)]
dp[0][0][0]=1
for i in range(n):
    for j in range(K+1):
        for k in range(2):
            nd=int(s[i])
            for d in range(10):
                ni,nj,nk=i+1,j,k
                if d!=0:
                    nj+=1
                if nj>K:
                    continue
                if nk==0:
                    if nd<d:
                        continue
                    if nd>d:
                        nk=1
                dp[ni][nj][nk]+=dp[i][j][k]
print(dp[n][K][0]+dp[n][K][1])