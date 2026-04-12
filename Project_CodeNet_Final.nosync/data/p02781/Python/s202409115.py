def f(n, k):
    # dp[ 上からの桁数 ][ N 未満フラグ ][ 0でない数の個数 ] := このパターンの総数
    # dp[i][smaller][j]
    # smaller = 0 のときNに一致
    # smaller = 1 のときN未満
    n = str(n)
    L = len(n)

    dp = [[[0]*(k+2) for i in range(2)] for j in range(L+1)]
    dp[0][0][0] = 1

    for i in range(L):
        D = int(n[i])
        for smaller in range(2):
            for j in range(k+1):
                for d in range((9 if smaller else D)+1):
                    dp[i+1][smaller or (d < D)][j + (d != 0)] += dp[i][smaller][j]

    return dp[L][0][k] + dp[L][1][k]


def main():
    N = int(input())
    K = int(input())

    print(f(N, K))


if __name__ == "__main__":
    main()
