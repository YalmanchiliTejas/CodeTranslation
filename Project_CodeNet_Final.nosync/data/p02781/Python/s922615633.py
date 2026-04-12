import itertools
import sys
import numpy as np
from collections import deque
from itertools import combinations
from functools import lru_cache
sys.setrecursionlimit(10**9)

@lru_cache(None)
def solve(N,K):
    # print(N,K)
    if N <= 10:
        if K == 0:
            return 1
        elif K == 1:
            return N
        else:
            return 0

    if K < 0 or len(str(N)) < K:
        return 0

    ans = 0
    m, last = divmod(N,10)
    ans += solve(m,K-1) * last + solve(m-1,K-1) * (9 - last) + solve(m,K)

    return ans


def main():
    N,K = map(int,[input(),input()])

    print(solve(N,K))

if __name__ == "__main__":
  main()
