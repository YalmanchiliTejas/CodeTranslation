def main():
    NOT_DET = 0
    SMALLER = 1

    s = input()
    n = len(s)  # 桁数

    k = int(input())

    dp = [[[0] * 2 for _ in range(k + 1)] for _ in range(n + 1)]
    # dp[上から何桁決めたか][0でない数字の個数][smaller=1]
    dp[0][0][0] = 1

    for i, ci in enumerate(s):
        for j in range(k + 1):
            dp[i + 1][j][SMALLER] = (
                    dp[i][j][SMALLER]
                    + dp[i][j][NOT_DET] * (1 if ci != '0' else 0)
                    + (dp[i][j - 1][SMALLER] if j > 0 else 0) * 9
                    + (dp[i][j - 1][NOT_DET] if j > 0 else 0) * max(0, int(ci) - 1)
            )

            dp[i + 1][j][NOT_DET] = dp[i][j][NOT_DET] if ci == '0' else (
                dp[i][j - 1][NOT_DET] if j > 0 else 0)

    print(sum(dp[n][k]))


if __name__ == '__main__':
    main()

# import sys
#
# sys.setrecursionlimit(10 ** 7)
#
# input = sys.stdin.readline
# rstrip()
# int(input())
# map(int, input().split())
