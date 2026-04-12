def e_almost_everywhere_zero():
    def digit_dp(n):  # n は文字列で与える
        """n 以下の非負整数で、0でない数字がちょうど K 個あるような数の個数"""
        digit = len(n)

        # dp[i][j][k]: i 桁目まで見たとき、N 未満が確定しているなら j = 1、
        # していないなら j = 0 とし、0 でない桁が k 個ある
        dp = [[[0] * (K + 2) for j in range(2)] for i in range(digit + 1)]
        dp[0][0][0] = 1
        for i in range(digit):
            for j in range(2):
                for k in range(K + 1):
                    lim = 9 if j == 1 else ord(n[i]) - ord('0')
                    for d in range(lim + 1):
                        # 0 でない桁が K + 1 個以上ある場合を同一視する
                        t = k + int(d != 0)
                        if t >= K + 1:
                            t = K + 1
                        dp[i + 1][j or (d < lim)][t] += dp[i][j][k]
        return sum(dp[digit][j][K] for j in range(2))

    N = input()
    K = int(input())
    return digit_dp(N)

print(e_almost_everywhere_zero())