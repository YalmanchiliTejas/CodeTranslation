N = input()
K = int(input())

n = len(N)

dp = [[[0]*2 for _ in range(5)] for _ in range(n+1)]
N0 = int(N[0])
if N0 == 0:
    dp[1][0][0] = 1
    dp[1][0][1] = 0
    dp[1][1][0] = 0
    dp[1][1][1] = 0
else:
    dp[1][0][0] = 0
    dp[1][0][1] = 1
    dp[1][1][0] = 1
    dp[1][1][1] = N0-1

for keta in range(1,n):
    Ni = int(N[keta])
    for k in range(4):
        for smaller in range(2):
            if smaller == 1:
                dp[keta+1][k+1][smaller] += dp[keta][k][smaller]*9
                dp[keta+1][k][smaller] += dp[keta][k][smaller]
            elif smaller == 0:
                if Ni == 0:
                    dp[keta+1][k][smaller] += dp[keta][k][smaller]
                else:
                    dp[keta+1][k][smaller+1] += dp[keta][k][smaller]
                    dp[keta+1][k+1][smaller+1] += dp[keta][k][smaller]*(Ni-1)
                    dp[keta+1][k+1][smaller] += dp[keta][k][smaller]
    
print(dp[n][K][0]+dp[n][K][1])


