# E - Almost Everywhere Zero
n=int(input())
K=int(input())
s=str(n)
n=len(s)
ans=0

dp=[[[0]*2 for j in range(K+1)] for i in range(n+1)]
dp[0][0][0]=1
for i in range(n):
    for j in range(K+1):
        for k in range(2):
            # if i>=n:continue
            nd=int(s[i])
            for d in range(10):
                ni=i+1
                nj=j
                nk=k
                if d!=0:nj+=1
                if nj>K:continue
                # k=0:nより小さいことが確定していない
                # k=1:nより小さいことが確定している
                if k==0:
                    # 次の桁が超えるとNG
                    if d>nd:continue
                    if d<nd:nk+=1
                dp[ni][nj][nk]+=dp[i][j][k]

ans=dp[n][K][0]+dp[n][K][1]
print(ans)               

