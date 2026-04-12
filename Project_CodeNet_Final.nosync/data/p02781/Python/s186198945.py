N=input()
K=int(input())

l=len(N)

dp=[[[0]*(K+2) for _ in range(2)] for _ in range(l+1)]

dp[0][1][0]=1

for i,c in enumerate(N):
    x=int(c)

    for j in range(2):
        for d in range(x+1 if j==1 else 10):
            for k in range(K+1):
                dp[i+1][x==d if j==1 else 0][k+1 if 0<d else k]+=dp[i][j][k]   

print(dp[l][0][K]+dp[l][1][K])