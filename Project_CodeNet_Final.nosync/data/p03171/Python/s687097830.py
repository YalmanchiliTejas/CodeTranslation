n = int(input())
a = list(map(int, input().split()))

dp = [[None] * len(a) for _ in a]

for i in range(len(a)-1, -1, -1):
    for j in range(i, len(a)):
        if i == j:
            dp[i][j] = a[i]
            continue

        dp[i][j] = max(a[j] - dp[i][j-1], a[i] - dp[i+1][j])

print(dp[0][len(a) - 1])