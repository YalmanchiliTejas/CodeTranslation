import sys
from itertools import accumulate
input = sys.stdin.readline


def readstr():
    return input().strip()


def readint():
    return int(input())


def readnums():
    return map(int, input().split())


def readstrs():
    return input().split()


def main():
    N = readint()
    A = list(readnums())
    a = list(accumulate(A))
    ans = 0
    MOD = 10 ** 9 + 7
    for i in range(N - 1):
        ans += A[i] * (a[-1] - a[i])
        ans %= MOD

    print(ans)


if __name__ == "__main__":
    main()
