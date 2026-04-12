import sys

readline = sys.stdin.readline
MOD = 998244353
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, s = map(int, readline().split())
    a = list(map(int, readline().split()))
    dp = [[0] * (s + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(n):
        cur = a[i]
        dp[i + 1][0] += 1
        for j in range(s + 1):
            dp[i + 1][j] += dp[i][j]
            dp[i + 1][j] %= MOD
            nx = cur + j
            if nx <= s:
                dp[i + 1][nx] += dp[i][j]
                dp[i + 1][nx] %= MOD
    ans = 0

    for i in range(1, n + 1):
        ans += dp[i][s]
        ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
