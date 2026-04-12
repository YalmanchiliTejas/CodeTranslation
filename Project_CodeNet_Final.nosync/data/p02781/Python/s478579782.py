import sys


def resolve(in_):
    N = next(in_).strip()
    K = int(next(in_))

    # exact
    dp0 = [[0] * (K + 1) for _ in range(len(N) + 1)]
    dp0[0][0] = 1
    # smaller
    dp1 = [[0] * (K + 1) for _ in range(len(N) + 1)]

    ord_zero = ord('0')
    for i, s in enumerate(map(lambda s: s - ord_zero, N)):
        for j in range(K + 1):
            dp1[i + 1][j] += dp1[i][j]
            if s > 0:
                dp1[i + 1][j] += dp0[i][j]
            else:
                dp0[i + 1][j] += dp0[i][j]
            if j < K:
                # smaller -> smaller
                dp1[i + 1][j + 1] += dp1[i][j] * 9
                # exact -> smaller
                dp1[i + 1][j + 1] += dp0[i][j] * max(0, (s - 1))
                # exact -> exact
                if s > 0:
                    dp0[i + 1][j + 1] += dp0[i][j]

    return dp0[len(N)][K] + dp1[len(N)][K]


def main():
    answer = resolve(sys.stdin.buffer)
    print(answer)


if __name__ == '__main__':
    main()
