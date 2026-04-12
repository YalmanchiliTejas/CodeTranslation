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

    csum = [0]
    csum.extend(accumulate(A))

    ans = 0
    for i, a in enumerate(A):
        ans = (ans + a * (csum[N] - csum[i + 1]) % MOD) % MOD

    print(ans)
    return


if __name__ == '__main__':
    main()
