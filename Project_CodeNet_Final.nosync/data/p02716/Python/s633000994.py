def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    if N % 2 == 0:
        dp = [[0]*2 for _ in range(N//2 + 1)]
        for i in range(N//2):
            dp[i+1][0] = dp[i][0] + A[2*i]

            dp[i+1][1] = max(dp[i][0], dp[i][1]) + A[2*i+1]

        print(max(dp[-1]))
    else:
        dp = [[0]*3 for _ in range(N//2 + 1)]
        for i in range(N//2):
            dp[i+1][0] = dp[i][0] + A[2*i]

            dp[i+1][1] = max(dp[i][0], dp[i][1]) + A[2*i+1]

            dp[i+1][2] = max(dp[i][0], dp[i][1], dp[i][2]) + A[2*i+2]

        print(max(dp[-1]))


if __name__ == '__main__':
    main()
