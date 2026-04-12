def main():
    N = input()
    K = int(input())

    N_list = [int(s) for s in N]
    N_len = len(N)

    # dp[i][j][k]
    # i: 桁数
    # j: 未満フラグ
    # k: 上からiまでの0でない数字の個数
    dp = [[[0 for _ in range(K + 2)] for _ in range(2)]
          for _ in range(N_len + 1)]
    dp[0][0][0] = 1

    for i in range(N_len):
        for j in range(2):
            for k in range(K + 1):
                x_max = 9 if j == 1 else N_list[i]
                for x in range(x_max + 1):
                    # print("i={},j={},k={},x={}".format(i, j, k, x))
                    if k <= K:
                        if x == 0:
                            dp[i + 1][j | (x < N_list[i])][k] += dp[i][j][k]
                        else:
                            dp[i + 1][j | (x < N_list[i])][k +
                                                           1] += dp[i][j][k]

    ans = dp[N_len][0][K] + dp[N_len][1][K]
    print(ans)

    # for i, a in enumerate(dp):
    #     for j, b in enumerate(a):
    #         for k, c in enumerate(b):
    #             print("dp[{}][{}][{}]={}".format(i, j, k, c))


main()
