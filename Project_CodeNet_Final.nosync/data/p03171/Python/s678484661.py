def kukan(n, a):
    dp = [[0] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = a[i]
    for i in range(n - 2, -1, -1):
        g0 = dp[i]
        g1 = dp[i + 1]
        for j in range(i + 1, n):
            L = a[i] - g1[j]
            R = a[j] - g0[j - 1]
            dp[i][j] = L if L > R else R
    return dp[0][n - 1]


n = int(input())
a = list(map(int, input().split()))
print(kukan(n, a))