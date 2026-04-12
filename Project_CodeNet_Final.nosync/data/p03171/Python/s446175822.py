n = int(input())
a = [int(x) for x in input().split()]

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for l in range(n):
        if l+i > n:
            continue
        else:
            if i % 2 == n % 2:
                dp[l][l+i] = max(a[l]+dp[l+1][l+i], a[l+i-1]+dp[l][l+i-1])
            else:
                dp[l][l+i] = min(-a[l]+dp[l+1][l+i], -a[l+i-1]+dp[l][l+i-1])

print(dp[0][n])
