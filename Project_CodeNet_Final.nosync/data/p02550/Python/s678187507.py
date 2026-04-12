# coding:UTF-8
import sys
from math import factorial

MOD = 10 ** 9 + 7
INF = 10000000000


def main():
    N, X, M = list(map(int, input().split()))     # スペース区切り連続数字

    dp = [0]
    dp.append(X)
    rp = 0
    rps = 0
    rps2 = 0
    for i in range(2, N+1):
        dp.append(dp[i-1]**2 % M)
        for j in range(1, i):
            if dp[i] == dp[j]:
                rp = 1
                rps = j
                rps2 = i
                break
        if rp != 0:
            break

    result = 0
    if rps > 0:
        for i in range(1, rps):
            result += dp[i]

        rc = (N - rps + 1) // (rps2 - rps)
        rpSum = 0
        for i in range(rps, rps2):
            rpSum += dp[i]
        result += rpSum * rc

        rca = (N - rps + 1) % (rps2 - rps)
        for i in range(rps, rps+rca):
            result += dp[i]
    else:
        for i in range(1, N+1):
            result += dp[i]

    # ------ 出力 ------#
    print("{}".format(result))

if __name__ == '__main__':
    main()
