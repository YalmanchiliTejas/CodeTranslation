N=input()
cnt=int(input())
L=len(N)
dp=[[[0]*(cnt+1) for j in range(2)] for i in range(L+1)]
dp[0][0][0]=1
for i in range(L):
    for j in range(2):
        for k in range(cnt+1):
            D=int(N[i])
            for d in range(10 if j else D+1):
                K=k+int(d!=0)
                if K>cnt:
                    continue
                dp[i+1][int(j or d<D)][K]+=dp[i][j][k]
print(dp[-1][0][-1]+dp[-1][1][-1])