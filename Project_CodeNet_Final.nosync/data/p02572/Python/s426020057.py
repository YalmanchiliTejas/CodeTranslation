# coding: utf-8
# Your code here!
# 幅優先探索（行きがけ）
import collections
import sys
import copy
import re
import math


def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int, sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


def main():
    N = I()
    AArray = LI()
    MOD = 1000000007
    aSum = sum(AArray)
    nowAsum = 0
    ans = 0

    for i in range(N-1):
        a = AArray[i]
        nowAsum += a
        asum = aSum-nowAsum
        asum %= MOD
        ans += a*asum % MOD
    ans %= MOD

    print(ans)


if __name__ == '__main__':
    main()
