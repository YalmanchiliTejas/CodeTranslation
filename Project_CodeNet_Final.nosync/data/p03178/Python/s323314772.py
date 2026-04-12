K = input()
D = int(input())

#dp[桁][余り][未満flag]
dp = [[[0 for k in range(2)] for j in range(D)] for i in range(len(K)+1)]
dp[0][0][0] = 1
s = 0
for i in range(len(K)):
    n = int(K[i])
    dp[i+1][(s+n)%D][0] = dp[i][s%D][0]
    s += n
    for j in range(D):
        for k in range(10):
            if k < n:
                dp[i+1][(j+k)%D][1] += dp[i][j][0]
            dp[i+1][(j+k)%D][1] += dp[i][j][1]
            dp[i+1][(j+k)%D][1] %= 1000000007

print(sum(dp[len(K)][0], -1)%1000000007)
