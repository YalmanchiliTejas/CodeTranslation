import sys
import bisect
import itertools
import collections
import fractions
import heapq
import math
from operator import mul
from functools import reduce
from functools import lru_cache


def solve():
    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7

    N = input()
    K = int(input())
    lenN = len(N)

    # has less number before
    dp0 = [[0]*5 for _ in range(lenN+1)]
    # not had yet
    dp1 = [[0]*5 for _ in range(lenN+1)]
    dp1[0][0] = 1

    for i in range(lenN):
        k = int(N[i])
        for zero in range(4):
            dp0[i+1][zero] += dp0[i][zero]
            dp0[i+1][zero+1] += dp0[i][zero] * 9
            if k != 0:
                dp0[i+1][zero] += dp1[i][zero]
                dp0[i+1][zero+1] += dp1[i][zero] * (k-1)
                dp1[i+1][zero+1] += dp1[i][zero]
            else:
                dp1[i+1][zero] += dp1[i][zero]


    ans = dp0[lenN][K] + dp1[lenN][K]
    print(ans)



if __name__ == '__main__':
    solve()