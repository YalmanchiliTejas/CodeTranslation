def main():
    EQ = 0
    LESS = 1

    *S, = map(int, input())
    L = len(S)
    K = int(input())

    dp = [[[0] * 2 for _ in range(K + 2)] for _ in range(L + 1)]
    dp[0][0][EQ] = 1

    for i, x in enumerate(S):
        for k in range(K + 1):  # ここをrange(K)にしてバグらせた
            if x == 0:
                dp[i + 1][k][EQ] += dp[i][k][EQ]  # x
            else:
                dp[i + 1][k + 1][EQ] += dp[i][k][EQ]  # x
                dp[i + 1][k + 1][LESS] += dp[i][k][EQ] * (x - 1)  # <x
                dp[i + 1][k][LESS] += dp[i][k][EQ]  # ==0
            dp[i + 1][k + 1][LESS] += dp[i][k][LESS] * 9  # !=0
            dp[i + 1][k][LESS] += dp[i][k][LESS]  # ==0

    print(sum(dp[L][K]))  # 全部0はK個の0でない数字を含まないので除去する必要がない


if __name__ == '__main__':
    main()
