def main():
    MOD = 10**9 + 7
    K = input()
    D = int(input())
    N = len(K)
    dp = [[[0]*D for j in range(2)] for i in range(N+1)]
    dp[0][0][0] = 1
    for i in range(N):
        for j in range(2):
            for k in range(D):
                lim = (9 if j else int(K[i]))
                for d in range(lim + 1):
                    # print(i, j, lim, d, j or d < lim)
                    dp[i+1][j or d < lim][(k + d) % D] += dp[i][j][k]
                    dp[i+1][j or d < lim][(k + d) % D] %= MOD
    print((dp[N][0][0]+dp[N][1][0]-1) % MOD)


if __name__ == '__main__':
    main()
