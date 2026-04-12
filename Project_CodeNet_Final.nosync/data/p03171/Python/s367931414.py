def main():
    N = int(input())
    A = list(map(int, input().split(' ')))
    dp = [[0 for _ in range(N)] for _ in range(N)]
    for length in range(1, N + 1):
        for left in range(N - length + 1):
            right = left + length - 1
            val = 0
            if left == right:
                val = A[left]
            else:
                val = max([
                    A[left] - dp[left + 1][right],
                    A[right] - dp[left][right - 1]
                ])
            dp[left][right] = val
    print(dp[0][N - 1])


if __name__ == '__main__':
    main()