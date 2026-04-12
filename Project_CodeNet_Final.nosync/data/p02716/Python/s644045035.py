def main():
    N = int(input())
    A = list(map(int, input().split()))
    dp = [[-1 * pow(10, 15)] * 3 for _ in range(N)]
    if N == 2:
        return max(A)
    dp[0][0] = A[0]
    dp[1][1] = A[1]
    dp[2][2] = A[2]
    for i in range(N):
        if i < 2:
            continue
        dp[i][0] = dp[i-2][0] + A[i]
        if i < 3:
            continue
        dp[i][1] = max(dp[i-3][0], dp[i-2][1]) + A[i]
        if i < 4:
            continue
        dp[i][2] = max(dp[i-4][0], dp[i-3][1], dp[i-2][2]) + A[i]
    if N % 2 == 0:
        return max(dp[-1][1], dp[-2][0])
    else:
        return max(dp[-1][2], dp[-2][1], dp[-3][0])
print(main())
