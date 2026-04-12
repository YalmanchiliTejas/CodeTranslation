import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, K = map(int, read().split())

    X = list(map(int, str(N)))
    L = len(X)

    dp1 = [[0] * (K + 1) for _ in range(L + 1)]
    dp2 = [[0] * (K + 1) for _ in range(L + 1)]
    dp1[0][0] = 1

    for i, x in enumerate(X):
        for j in range(K + 1):
            if x != 0:
                if j > 0:
                    dp1[i + 1][j] = dp1[i][j - 1]
            else:
                dp1[i + 1][j] = dp1[i][j]
            if j > 0:
                dp2[i + 1][j] = dp2[i][j - 1] * 9
                if x != 0:
                    dp2[i + 1][j] += dp1[i][j - 1] * (x - 1)
            dp2[i + 1][j] += dp2[i][j]
            if x != 0:
                dp2[i + 1][j] += dp1[i][j]

    print(dp1[L][K] + dp2[L][K])
    return


if __name__ == '__main__':
    main()
