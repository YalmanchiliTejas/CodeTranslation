from functools import reduce
from fractions import gcd
import math
import bisect
import itertools
import sys
from collections import defaultdict
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
INF = float("inf")


def main():
    S = input()[:-1]
    
    if S in ["AAA", "BBB"]:
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
    main()