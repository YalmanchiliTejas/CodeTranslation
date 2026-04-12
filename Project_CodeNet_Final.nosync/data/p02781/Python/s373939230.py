N = input()
l = len(N)
K = int(input())
dp = [[[0]*2 for i in range(K+1)] for j in range(l)]
dp[0][0][0] = 1
dp[0][1][0] = int(N[0])-1
dp[0][1][1] = 1
for i in range(l-1):
    for j in range(K+1):
        for d in range(10):
            if d == 0:
                dp[i+1][j][0] += dp[i][j][0]
                if N[i+1] == '0':
                    dp[i+1][j][1] += dp[i][j][1]
                else:
                    dp[i+1][j][0] += dp[i][j][1]
            else:
                if j==K:
                    continue
                dp[i+1][j+1][0] += dp[i][j][0]
                if int(N[i+1])>d:
                    dp[i+1][j+1][0] += dp[i][j][1]
                elif int(N[i+1])==d:
                    dp[i+1][j+1][1] += dp[i][j][1]
print(dp[-1][-1][0]+dp[-1][-1][1])



        
