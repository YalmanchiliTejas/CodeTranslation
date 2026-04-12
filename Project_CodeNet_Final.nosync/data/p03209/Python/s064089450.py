n, x = map(int, input().split())

s = [1] * (n+1)
for i in range(1, n+1):
    s[i] = 2 * s[i-1] + 3

dp = [dict() for _ in range(n+1)]
dp[0][1] = 1
dp[0][0] = 0


def solve(i, j):
    if j in dp[i]:
        return dp[i][j]

    if i == 0:
        return dp[i][j]

    if j == 0:
        return 0

    val = 0
    if s[i] <= j:
        val = solve(i-1, s[i-1]) * 2 + 1
    elif s[i-1] + 2 <= j:
        val = solve(i-1, s[i-1]) + 1 + solve(i-1, j-s[i-1]-2)
    else:
        val = solve(i-1, j-1)

    dp[i][j] = val
    return val


print(solve(n, x))
