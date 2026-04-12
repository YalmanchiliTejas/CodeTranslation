import sys
import math  # noqa
import bisect  # noqa
import queue  # noqa


def input():
    return sys.stdin.readline().rstrip()


def main():
    N, K = map(int, input().split())

    res = 0
    for b in range(K + 1, N + 1):
        p = N // b
        q = N - b * p
        res += max(0, q - K + 1)
        res += p * max(0, b - 1 - K + 1)
        if K == 0:
            res -= 1

    print(res)


if __name__ == '__main__':
    main()
