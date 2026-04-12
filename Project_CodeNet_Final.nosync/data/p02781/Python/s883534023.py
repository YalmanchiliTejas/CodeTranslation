def e_almost_everywhere_zero():
    N = input()
    K = int(input())

    def digit_dp(n):  # n は文字列で与える
        """n 以下の非負整数で、0でない数字がちょうど K 個あるような数の個数"""
        digit = len(n)

        dp = [[[0] * (K + 2) for j in range(2)] for i in range(digit + 1)]
        dp[0][0][0] = 1
        for i in range(digit):
            for j in range(2):
                for k in range(K + 1):
                    lim = 9 if j == 1 else ord(n[i]) - ord('0')
                    for d in range(lim + 1):
                        if d != 0:
                            t = k + 1
                            if t >= K + 2:
                                t = K + 1
                        else:
                            t = k
                        dp[i + 1][j or (d < lim)][t] += dp[i][j][k]
        return sum(dp[digit][j][K] for j in range(2))
    return digit_dp(N)

print(e_almost_everywhere_zero())