def main():
    import sys
    input = sys.stdin.readline

    mod = 1000000007
    nmax = 1001  # change here
    fac = [0] * (nmax + 1)
    finv = [0] * (nmax + 1)
    inv = [0] * (nmax + 1)
    fac[0] = 1
    fac[1] = 1
    finv[0] = 1
    finv[1] = 1
    inv[1] = 1
    for i in range(2, nmax):
        fac[i] = fac[i - 1] * i % mod
        inv[i] = mod - inv[mod % i] * (mod // i) % mod
        finv[i] = finv[i - 1] * inv[i] % mod

    N, A, B, C, D = map(int, input().split())

    dp = [[0] * (N+1) for _ in range(B+1)]
    for i in range(B+1):
        dp[i][0] = 1

    for i in range(A, B+1):
        for j in range(N+1):
            dp[i][j] = dp[i-1][j]
        for j in range(N+1):
            if (N-j) // i < C:
                continue
            n_max = min(D, (N-j)//i)
            for n in range(C, n_max+1):
                tmp = (((fac[N-j] * finv[N-j-i*n])%mod * pow(finv[i], n, mod))%mod * finv[n])%mod
                dp[i][j+i*n] = (dp[i][j+i*n] + (dp[i-1][j] * tmp)%mod) % mod
    print(dp[-1][-1])


if __name__ == '__main__':
    main()
