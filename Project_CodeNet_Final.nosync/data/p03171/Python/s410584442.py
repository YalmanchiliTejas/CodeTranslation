def main():
    n = int(input())
    *a, = map(int, input().split())

    memo = [[-1] * n for _ in range(n)]
    for i, x in enumerate(a):
        memo[i][i] = x

    for l in range(n - 1, -1, -1):  # ここの感覚がつかめない
        for r in range(l + 1, n):
            memo[l][r] = max(
                a[l] - memo[l + 1][r],
                a[r] - memo[l][r - 1]
            )

    print(memo[0][n - 1])


if __name__ == '__main__':
    main()
