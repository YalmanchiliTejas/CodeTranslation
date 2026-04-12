def main():
    from collections import defaultdict

    inf = 10 ** 15

    N = int(input())
    *a, = map(int, input().split())

    it = iter(a)

    dp = [defaultdict(lambda: -inf) for _ in range(N + 1)]
    dp[0][0] = 0
    dp[1][0] = 0
    dp[1][1] = next(it)
    for i, x in enumerate(it, 2):
        mi = (i - 1) // 2
        ma = (i + 1) // 2
        for taken_count in range(mi, ma + 1):
            dp[i][taken_count] = max(
                dp[i - 1][taken_count],
                dp[i - 2][taken_count - 1] + x
            )

    ans = dp[N][N // 2]

    print(ans)


if __name__ == '__main__':
    main()
