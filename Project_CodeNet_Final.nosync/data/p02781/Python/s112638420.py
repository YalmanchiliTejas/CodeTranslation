N=int(input())
K=int(input())

sN=str(N)
keta=len(sN)

#dp[i][j][t]=Nと同じ桁数の整数で上からi桁目までで0でない数字がj個あるものの個数
dp=[[[0]*2 for __ in range(K+1)] for _ in range(keta+1)]
dp[0][0][1]=1

for i in range(keta):
    for j in range(K+1):
        for k in range(2):
            for n in range(10):
                if k==1 and n>int(sN[i]): break
                ni=i+1
                nj=j if n==0 else j+1
                if nj>K: continue
                nk=1 if k==1 and n==int(sN[i]) else 0
                dp[ni][nj][nk]+=dp[i][j][k]

print(dp[keta][K][0]+dp[keta][K][1])
