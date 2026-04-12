# -*- coding: utf-8 -*-


def main():
    s = list(input())
    n = len(s)
    large_k = int(input())
    dp = [[[0 for k in range(2)] for j in range(4)] for i in range(105)]
    dp[0][0][0] = 1

    # See:
    # https://www.youtube.com/watch?v=JQmQjJd-sLA&feature=youtu.be
    for i in range(n):
        for j in range(4):
            for k in range(2):
                nd = int(s[i])

                for digit in range(10):
                    ni, nj, nk = i + 1, j, k

                    if digit != 0:
                        nj += 1
                    if nj > large_k:
                        continue
                    if k == 0:
                        if digit > nd:
                            continue
                        if digit < nd:
                            nk = 1

                    dp[ni][nj][nk] += dp[i][j][k]

    print(dp[n][large_k][0] + dp[n][large_k][1])


if __name__ == '__main__':
    main()
