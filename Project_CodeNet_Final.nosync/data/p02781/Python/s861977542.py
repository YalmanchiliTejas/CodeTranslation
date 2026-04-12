N = int(input())
K = int(input())
S = str(N)
L = len(S)

dp = [[[1, 0], [0, 0], [0, 0], [0, 0]] for i in range(L)]
dp[0] = [[1, 0], [int(S[0])-1, 1], [0, 0], [0, 0]]

for l in range(1,L):
    s = int(S[l])
    if s == 0:
        for k in range(1,4):
            dp[l][k][1] += dp[l-1][k][1]
    else:
        for k in range(1,4):
            dp[l][k][1] += dp[l-1][k-1][1]
            dp[l][k][0] += dp[l-1][k][1]
    for k in range(1,4):
        dp[l][k][0] += dp[l-1][k-1][0]*9 + dp[l-1][k][0]
        dp[l][k][0] += dp[l-1][k-1][1]*max(0,s-1)

print(sum(dp[L-1][K]))