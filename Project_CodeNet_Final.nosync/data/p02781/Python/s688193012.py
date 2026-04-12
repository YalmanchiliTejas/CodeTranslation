n=input()
l=len(n)
K=int(input())
dp=[[[0]*2 for i in range(4)]for j in range(105)]
dp[0][0][0]=1
for i in range(l):
    for j in range(4):
        for k in range(2):
            nd=int(n[i])
            for d in range(10):
                ni=i+1
                nj=j
                nk=k
                if d!=0:
                    nj+=1
                if nj>K:
                    continue
                if k==0:
                    if nd>d:
                        nk=1
                    if nd<d:
                        continue
                dp[ni][nj][nk]+=dp[i][j][k]
print(dp[l][K][1]+dp[l][K][0])
