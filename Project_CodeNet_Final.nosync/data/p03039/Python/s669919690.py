import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def comb_mod(n, r):
    res = 1
    r = min(n - r, r)

    for i in range(r):
        res *= (n - i)
        res %= MOD
        res *= pow((r - i), MOD - 2, MOD)

    return res


def main():
    n, m, k = list(map(int, readline().split()))

    com = comb_mod(n * m - 2, k - 2)
    x = 0
    y = 0

    for i in range(n):
        right = n - 1 - i
        x += (right + 1) * right // 2
        x %= MOD

    for i in range(m):
        down = m - 1 - i
        y += (down + 1) * down // 2
        y %= MOD

    ans = 0
    ans += m ** 2 * x * com
    ans += n ** 2 * y * com
    ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
