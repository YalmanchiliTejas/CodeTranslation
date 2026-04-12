from bisect import bisect_right, bisect_left
from itertools import groupby, permutations, combinations
from fractions import gcd
import numpy as np
from sys import stdin, stderr


def lcm(x, y):
    return (x * y) // gcd(x, y)


def main():
    N, M = [int(x) for x in input().split()]
    ret = "Yes" if N == M else "No"
    return ret


if __name__ == "__main__":
    print(main())