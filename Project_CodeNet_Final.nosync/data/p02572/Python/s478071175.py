from collections import Counter
import sys

sys.setrecursionlimit(10 ** 6)

mod = 1000000007
inf = int(1e18)

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def inverse(a):
    return pow(a, -1, mod)


def main():
    n = int(input())
    a = list(map(int, input().split()))
    c = [0] * (n+1)
    for i in range(n):
        c[i+1] = c[i] + a[i]

    ans = 0
    for i in range(n):
        ans += a[i] * (c[n] - c[i+1])
        ans %= mod
    print(ans)
main()
