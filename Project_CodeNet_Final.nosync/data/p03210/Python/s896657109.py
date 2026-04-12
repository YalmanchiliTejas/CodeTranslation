# -*- coding: utf-8 -*-
"""
A - 753

"""
import sys
from sys import stdin
input = stdin.readline


def solve():
    X = int(input())
    return 'YES' if X in [7, 5, 3] else 'NO'


def main(args):
    ans = solve()
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
