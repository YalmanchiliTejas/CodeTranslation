N = input()
K = int(input())

ln = len(N)

dp = [[[0] * 4 for _ in range(2)] for _ in range(ln + 1)]
dp[0][0][0] = 1

for i in range(1, ln + 1):
    for j in range(2):
        for k in range(4):
            num = int(N[i-1])
            if j:
                l_mx = 9
            else:
                l_mx = num

            for l in range(l_mx + 1):
                if l == 0:
                    dp[i][j or l < num][k] += dp[i-1][j][k]
                else:
                    if k > 0:
                        dp[i][j or l < num][k] += dp[i-1][j][k-1]

ans = dp[ln][0][K] + dp[ln][1][K]
print(ans)
