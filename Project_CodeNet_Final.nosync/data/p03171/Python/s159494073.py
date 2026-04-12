def deque(n, arr):
    dp = [[0] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = arr[i]

    for l in range(n-2, -1, -1):
        for r in range(l+1, n):
            L = arr[l] - dp[l+1][r]
            R = arr[r] - dp[l][r-1]
            dp[l][r] = L if L > R else R
    return dp[0][n-1]

n = int(input())
arr = [int(x) for x in input().split()]
print(deque(n, arr))
