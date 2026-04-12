def main():
    import sys
    input = sys.stdin.readline

    N = list(map(int, list(input()[:-1])))
    K = int(input())
    L = len(N)

    # dp[i][j][k]
    # i 桁目まで決めて
    # j 個の非0を使って
    # k = 0 : そこまでの桁はNと一致
    # k = 1 : そこまでの桁でN未満であることが確定
    dp = [[[0] * 2 for _ in range(K + 2)] for _ in range(L + 1)]
    dp[0][0][0] = 1

    for i, x in enumerate(N):
        for k in range(K + 1):
            # 桁ごと数え上げ
            if x == 0:
                # x == 0
                dp[i + 1][k][0] += dp[i][k][0]
            else:
                # x == 0
                dp[i + 1][k][1] += dp[i][k][0]
                # 0 < n < x
                dp[i + 1][k + 1][1] += dp[i][k][0] * (x - 1)
                # n == x
                dp[i + 1][k + 1][0] += dp[i][k][0]
            # N未満で次の桁に1~9を入れる
            dp[i + 1][k + 1][1] += dp[i][k][1] * 9
            # N未満で次の桁に0を入れる
            dp[i + 1][k][1] += dp[i][k][1]

    print(sum(dp[L][K]))  

if __name__ == '__main__':
    main()
