from collections import defaultdict, deque
import bisect
import sys

sys.setrecursionlimit(100000)

MIN = -10 ** 9
MAX = 10 ** 9 + 7


def d(n):
    divisors = []
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)

    return divisors


def main():
    N = int(input())
    A = [
        int(input())
        for _ in range(N)
    ]

    res = [A[-1]]  # 4,5,9,,,
    for ai in reversed(A[:-1]):
        if ai >= res[-1]:
            res.append(ai)
            continue
        ind = bisect.bisect_right(res, ai)
        res[ind] = ai
    print(len(res))


if __name__ == '__main__':
    main()
