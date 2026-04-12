N=input()
K=int(input())

dpsm=[[0]*(K+1) for _ in range(len(N))] #dpsm[i][k]
dp=[[0]*(K+1) for _ in range(len(N))]

dpsm[0][0]=1
dpsm[0][1]=int(N[0])-1
dp[0][1]=1

for i in range(1,len(N)):
    for k in range(K-1,-1,-1):
        dpsm[i][k+1]+=dpsm[i-1][k]*9

    
    if N[i]=="0":
        for k in range(K,-1,-1):
            dpsm[i][k]+=dpsm[i-1][k]
            dp[i][k]+=dp[i-1][k]
    else:
        for k in range(K-1,-1,-1):
            dpsm[i][k+1]+=dp[i-1][k]*(int(N[i])-1)
            dp[i][k+1]+=dp[i-1][k]

        for k in range(K,-1,-1):
            dpsm[i][k]+=dpsm[i-1][k]
            dpsm[i][k]+=dp[i-1][k]
          
print(dp[-1][-1]+dpsm[-1][-1])
