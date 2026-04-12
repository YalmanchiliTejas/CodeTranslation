MOD = 10**9 + 7
def ketadp3(a, b):
    L = len(a)

    dp = [[[0 for i in range(2)] for j in range(b)] for k in range(L + 1)]
    dp[0][0][0] = 1
    for i in range(L):
        D = int(a[i])
        for k in range(b):
            for j in range(2):
                for d in range(10 if j else D+1):
                    dp[i + 1][(k + d) % b][j or (d < D)] += dp[i][k][j]
                    dp[i + 1][(k + d) % b][j or (d < D)] %= MOD

    print((dp[L][0][0] + dp[L][0][1] - 1) % MOD)


def main():
    n = input()
    d = int(input())
    ketadp3(n, d)


if __name__ == '__main__':
    main()