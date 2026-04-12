N=list(input())
K=int(input())
N=list(map(int,N))
#print(N)
dp=[[[0 for _ in range(4)] for _ in range(len(N))] for _ in range(2)]
for i in range(len(N)):
    num=N[i]
    mayover=0
    if i==0:
        id=0
        for j in range(10):
            if j==num:
                id=1
            elif j>num:
                break
            if j==0:
                dp[id][i][0]=dp[id][i][0]+1
            else:
                dp[id][i][1] = dp[id][i][1] + 1
    else:
        for j in range(2):
            for l in range(4):
                if j==0:
                    dp[j][i][l] = dp[j][i][l] + dp[j][i - 1][l]
                    if l != 0:
                        dp[j][i][l] = dp[j][i][l] + 9*dp[j][i - 1][l - 1]
                else:
                    if num==0:
                        for l in range(4):
                            dp[j][i][l] = dp[j][i - 1][l]
                    else:
                        dp[0][i][l] = dp[0][i][l] + dp[j][i - 1][l]
                        if l != 0:
                            dp[0][i][l] = dp[0][i][l] + (num - 1) * dp[j][i - 1][l - 1]
                            dp[1][i][l] = dp[1][i][l] + dp[j][i - 1][l - 1]
    #print(dp[0][i],dp[1][i])
    #input()
print(dp[0][len(N)-1][K]+dp[1][len(N)-1][K])






