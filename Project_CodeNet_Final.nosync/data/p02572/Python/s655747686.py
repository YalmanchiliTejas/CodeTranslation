from functools import reduce
from fractions import gcd
import math
import bisect
import itertools
import sys
input = sys.stdin.readline
INF = float("inf")


# 処理内容
def main():
    N = int(input())
    A = list(map(int, input().split()))
    s = sum(A)**2
    t = 0
    for a in A:
        t += a**2
    
    ans = (s - t) // 2
    print(ans % 1000000007)


if __name__ == '__main__':
    main()