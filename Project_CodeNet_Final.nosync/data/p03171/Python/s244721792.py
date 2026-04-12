def solve(l, r, A, dp):
    if r - l < 2:
        return max(A[l:r + 1])

    x1 = dp[l + 2][r] if dp[l + 2][r] != -1 else solve(l + 2, r, A, dp)
    x2 = dp[l + 1][r - 1] if dp[l + 1][r - 1] != -1 else solve(l + 1, r - 1, A, dp)
    x3 = dp[l][r - 2] if dp[l][r - 2] != -1 else solve(l, r - 2, A, dp)

    dp[l][r] = max(min(x1, x2) + A[l], min(x2, x3) + A[r])

    return dp[l][r]


N = int(input())
A = [int(i) for i in input().split()]
dp = [[-1] * N for i in range(N)]
print(2*solve(0, N-1, A, dp)-sum(A))
