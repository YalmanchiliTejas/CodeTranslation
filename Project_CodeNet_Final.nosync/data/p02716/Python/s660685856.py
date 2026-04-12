from collections import defaultdict


def main():
    N = int(input())
    A = list(map(int, input().split()))

    def default():
        return -float("inf")
    dp = [defaultdict(default) for _ in range(N)]
    dp[0][0] = 0
    dp[0][1] = A[0]
    dp[1][0] = 0
    dp[1][1] = max(A[0], A[1])
    for i in range(2, N):
        dp[i][i//2] = max(dp[i-2][i//2-1] + A[i], dp[i-1][i//2])
        dp[i][i//2+1] = max(dp[i-2][i//2] + A[i], dp[i-1][i//2+1])
    print(dp[N-1][N//2])


if __name__ == "__main__":
    main()
