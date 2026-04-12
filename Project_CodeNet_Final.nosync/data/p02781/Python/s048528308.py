n = list(map(int, list(input())))
k = int(input())

# 上の桁からDP
# 大きさが微妙な場合は分ける
# dp[桁][0の個数]

def solve(n, k):
    if k == 0:
        return 1
    if n == []:
        return 0
    dp = [[0 for _ in range(k+1)] for _ in range(len(n))]
    dp[0][0] = 1
    dp[0][1] = n[0] - 1
    for i in range(len(n) - 1):
        for j in range(k + 1):
            if j == 0:
                dp[i+1][0] = dp[i][0]
            else:
                dp[i+1][j] = dp[i][j-1] * 9 + dp[i][j]
    # first non-0
    i = 1
    while i < len(n) and n[i] == 0:
        i += 1
    return dp[len(n) - 1][k] + solve(n[i:], k-1)

print(solve(n, k))