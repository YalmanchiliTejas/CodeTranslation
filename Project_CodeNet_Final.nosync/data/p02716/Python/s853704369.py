# -*- coding: utf-8 -*-
##################################
# University of Wisconsin-Madison
# Author: Yaqi Zhang
##################################

# standard library
import sys
from functools import lru_cache

sys.setrecursionlimit(10**9)

Input = lambda: sys.stdin.readline().rstrip()
IntRead = lambda: int(Input())
LineRead = lambda: list(map(int, Input().split()))

def main():
    N = IntRead()
    INF = 10**18
    nums = LineRead()
    @lru_cache(None)
    def dp(idx, n):
        if idx >= N:
            return -INF
        if N - idx + 2 < 2 * n:
            return -INF
        if n == 0:
            return 0
        elif n == 1:
            return max(nums[idx:])
        return max(nums[idx] + dp(idx + 2, n - 1), dp(idx + 1, n))
    print(dp(0, N // 2))


if __name__ == "__main__":
    main()
