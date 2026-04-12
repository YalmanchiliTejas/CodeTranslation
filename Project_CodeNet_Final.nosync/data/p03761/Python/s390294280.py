import sys
import re
import math
import collections
import decimal
import bisect
import itertools
import fractions
import functools
import copy

# import heapq
# from collections import deque
# import decimal

sys.setrecursionlimit(10000001)
INF = sys.maxsize
MOD = 10 ** 9 + 7

ni = lambda: int(sys.stdin.readline())
ns = lambda: map(int, sys.stdin.readline().split())
na = lambda: list(map(int, sys.stdin.readline().split()))

# ===CODE===
tMOD = 998244353


def main():
    n = ni()
    dic = {chr(i): INF for i in range(97, 97 + 26 )}
    for _ in range(n):
        s = list(input())
        c = collections.Counter(s)
        for k, v in dic.items():
            if k in c.keys():
                dic[k] = min(dic[k], c[k])
            else:
                dic[k] = 0

    word = list(dic.items())
    word.sort()

    ans = ""
    for k, v in word:
        if v < INF:
            ans += k * v

    print(ans)

    tmp = 0


if __name__ == '__main__':
    main()
