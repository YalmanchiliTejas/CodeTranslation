N=int(input())
K=int(input())
s=str(N)
N=len(s)

dp=[[[0]*2 for j in range(K+1)] for i in range(N+1)]
dp[0][0][0]=1

for i in range(N):
    for j in range(K+1):
        for k in range(2):
            cd=int(s[i])
            for nd in range(10):
                ni=i+1
                nj=j
                nk=k
                if nd!=0:nj+=1
                if nj>K:continue
                if k==0:
                    if nd>cd:continue
                    if nd<cd:nk=1
                dp[ni][nj][nk]+=dp[i][j][k]
print(dp[N][K][0]+dp[N][K][1])
