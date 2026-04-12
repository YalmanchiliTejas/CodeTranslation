from sys import stdin, setrecursionlimit


def main():
    input = stdin.buffer.readline
    n = list(map(int, list(input()[:-1].decode())))
    N = len(n)
    k = int(input())

    dp = [[[0] * (k + 1) for _ in range(2)] for _ in range(N + 1)]
    dp[0][0][0] = 1
    for i in range(1, N + 1):
        num = n[i - 1]
        for j in range(k + 1):
            dp[i][1][j] += dp[i - 1][1][j]
            if num != 0:
                dp[i][1][j] += dp[i - 1][0][j]
            else:
                dp[i][0][j] += dp[i - 1][0][j]
            if j >= 1:
                dp[i][1][j] += 9 * dp[i - 1][1][j - 1]
                if num != 0:
                    dp[i][0][j] += dp[i - 1][0][j - 1]
                    dp[i][1][j] += (num - 1) * dp[i - 1][0][j - 1]

    print(dp[N][0][k] + dp[N][1][k])


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
