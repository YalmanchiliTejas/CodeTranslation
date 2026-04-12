import sys

# import re
import math
import collections
# import decimal
import bisect
import itertools
import fractions
# import functools
import copy
import heapq
import decimal
# import statistics
import queue

sys.setrecursionlimit(10000001)
INF = 10 ** 16
MOD = 10 ** 9 + 7

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))


# ===CODE===


def main():
    n = ni()
    a = [ni() for _ in range(n)]

    a.sort()

    ans1 = []
    ans2 = []
    if not n % 2:
        small = a[:n // 2]
        large = a[n // 2:]
        for i in range(n // 2):
            ans2.append(large[i])
            ans2.append(small[i])

        tmp_ans = 0
        for i in range(1, n):
            tmp_ans += abs(ans2[i - 1] - ans2[i])

        print(tmp_ans)

    else:
        small1 = a[:n // 2 + 1]
        large1 = a[n // 2 + 1:]
        small1.insert(0, small1[-1])
        del small1[-1]
        for i in range(n // 2):
            ans1.append(small1[i])
            ans1.append(large1[i])
        ans1.append(small1[n // 2])

        small2 = a[:n // 2]
        large2 = a[n // 2:]
        large2.append(large2[0])
        del large2[0]
        for i in range(n // 2):
            ans2.append(large2[i])
            ans2.append(small2[i])
        ans2.append(large2[n // 2])

        tmp_ans1 = 0
        tmp_ans2 = 0
        for i in range(1, n):
            tmp_ans1 += abs(ans1[i - 1] - ans1[i])
            tmp_ans2 += abs(ans2[i - 1] - ans2[i])

        print(max(tmp_ans1, tmp_ans2))

if __name__ == '__main__':
    main()
