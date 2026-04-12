
def resolve():
    MOD = 10**9+7
    K = input()
    D = int(input())
    N = len(K)

    # dp[keta][D][smaler]
    dp = [[[0]*2 for _ in range(D)] for _ in range(N+1)]
    dp[0][0][0] = 1

    for i in range(N):
        num = int(K[i])
        for j in range(D):
            for smaller in range(2):
                for d in range(10):
                    ni = i+1
                    nsmaller = smaller
                    nj = (j+d)%D
                    if smaller == 0:
                        if d < num:
                            nsmaller = 1
                        if d > num:
                            continue
                    dp[ni][nj][nsmaller] += dp[i][j][smaller]
                    dp[ni][nj][nsmaller] %= MOD
    print((dp[N][0][1] + dp[N][0][0] - 1) % MOD)


if __name__ == "__main__":
    resolve()
