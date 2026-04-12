import sys


def main():
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())

    digits = 0
    nc = n
    while nc:
        nc //= 10
        digits += 1

    dp = [[0] * (k+2) for _ in range(2)]
    dp[0][0] = 1

    for i in range(digits):
        digit = (n // (10 ** (digits - 1 - i))) % 10
        ndp = [[0] * (k+2) for _ in range(2)]
        for j in range(k+1):
            ndp[1][j] += dp[1][j]  # 0
            ndp[1][j+1] += dp[1][j] * 9

            if digit == 0:
                ndp[0][j] += dp[0][j]
            else:
                ndp[1][j] += dp[0][j]  # 0
                ndp[1][j+1] += dp[0][j] * (digit-1)  # less
                ndp[0][j+1] += dp[0][j]  # same
        dp = ndp
    print(dp[1][k] + dp[0][k])


if __name__ == '__main__':
    main()