N = input()
n = len(N)
K = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(N[i])
a.insert(0,0)
dp = [[[0,0,0,0],[0,0,0,0]] for _ in range(n+1)]
dp[0][0][0] = 1
for i in range(1,n+1):
    for f in range(2):
        if f == 0:
            for k in range(4):
                if a[i] != 0:
                    if k !=0:
                        dp[i][0][k] = dp[i-1][0][k-1]
                    dp[i][1][k] += dp[i-1][0][k]
                    if k == 3:
                        continue
                    dp[i][1][k+1] += dp[i-1][0][k] * (a[i] - 1)
                if a[i] == 0:
                    dp[i][0][k] = dp[i-1][0][k]
        if f == 1:
            for k in range(4):
                if k!=0:
                    dp[i][1][k] += dp[i-1][1][k] + dp[i-1][1][k-1] * 9
                if k == 0:
                    dp[i][1][k] += dp[i-1][1][k]
ans = dp[n][0][K] + dp[n][1][K]
print(ans)