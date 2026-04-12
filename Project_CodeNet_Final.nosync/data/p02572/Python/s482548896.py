import sys
from itertools import accumulate

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    N, *A = map(int, read().split())

    total = sum(A) % MOD

    ans = total * total % MOD
    for a in A:
        ans = (ans - a * a) % MOD

    ans = ans * pow(2, MOD - 2, MOD) % MOD

    print(ans)
    return


if __name__ == '__main__':
    main()
