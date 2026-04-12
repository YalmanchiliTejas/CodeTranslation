import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    N = int(readline())
    A = list(map(int, readline().split()))

    s = sum(A) % MOD
    ans = 0

    for x in A:
        s = s - x
        s %= MOD
        ans += s * x
        ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
