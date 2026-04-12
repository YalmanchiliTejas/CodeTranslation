def main():
    MOD = 998244353

    N, S = map(int, input().split())
    A = tuple(map(int, input().split()))

    DP0 = [[0] * (S + 1) for _ in range(N + 1)]
    DP1 = [[0] * (S + 1) for _ in range(N + 1)]
    DP2 = [[0] * (S + 1) for _ in range(N + 1)]

    DP0[0][0] = 1

    for i in range(N):
        DP0[i + 1][0] = DP0[i][0] 
        DP1[i + 1][0] = DP0[i][0] + DP1[i][0]
        a = A[i]
        if a > S:
            for j in range(1, S + 1):
                DP1[i + 1][j] = DP1[i][j] #以前から合計jになっている場合のみOK
        else:
            for j in range(1, a):
                DP1[i + 1][j] = DP1[i][j] #以前から合計jになっている場合のみOK
            for j in range(a, S + 1):
                DP1[i + 1][j] = (DP1[i][j] + DP0[i][j - a] + DP1[i][j - a]) % MOD
                # DP[i + 1][j][1] = (DP[i][j][0] + DP[i][j][1] + DP[i + 1][j - a][1]) % MOD

        DP2[i + 1][S] = (DP1[i][S] + DP2[i][S])
        if a <= S:
            DP2[i + 1][S] += DP0[i][S - a] + DP1[i][S - a]
        DP2[i + 1][S] %= MOD

    print (DP2[N][S])

    # for i in range(N + 1):
    #     print (DP[i])

if __name__ == '__main__':
    main()