#!/usr/bin/env python
import math


def main():
    N, K = map(int, input().split())

    if K == 0:
        return N * N

    ans = 0
    for n in range(1, N + 1):
        if n <= K:
            pass
        else:
            ans += (N // n) * (n - K)
            ans += (N % n) - K + 1 if (N % n) - K + 1 > 0 else 0

    return ans


if __name__ == '__main__':
    print(main())