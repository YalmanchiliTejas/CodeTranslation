def main():
    N = int(input())
    A = list(map(int, input().split()))
    dp = [[0] * N for _ in range(N+1)]
    dp[1] = A
    for length in range(2, N+1):
        for idx in range(N - length + 1):
            dp[length][idx] = max(A[idx] - dp[length-1][idx+1],
                                  A[idx+length-1] - dp[length-1][idx])
    print(dp[N][0])


if __name__ == "__main__":
    main()
