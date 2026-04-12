#!/usr/bin/env python3
import sys
from collections import deque, Counter
from heapq import heappop, heappush
from bisect import bisect_right
from itertools import accumulate

sys.setrecursionlimit(10**6)
INF = 10**12
m = 10**9 + 7


def main():
    N, X, M = map(int, input().split())
    # A = [0] * (M)
    # A[X] = 1
    now = [X]
    nowS = set()
    nowS.add(X)
    loop = -1
    for i in range(N - 1):
        tmp = pow(now[-1], 2, M)
        if tmp in nowS:
            loop = now.index(tmp)
            break
        else:
            now.append(tmp)
            nowS.add(tmp)
    # print(now, loop)
    if loop == -1:
        print(sum(now))
    else:
        ans = sum(now[:loop])
        N -= loop
        # print(N)
        SUM = sum(now[loop:])
        ans += (N // (len(now)-loop)) * SUM
        N %= len(now)-loop
        # print(N)
        ans += sum(now[loop:loop+N])
        print(ans)


if __name__ == "__main__":
    main()
