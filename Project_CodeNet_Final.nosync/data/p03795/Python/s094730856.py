# -*- coding: utf-8 -*-
"""
A - Restaurant
https://atcoder.jp/contests/abc055/tasks/abc055_a

"""
import sys


def solve(N):
    return N*800 - (N//15*200)


def main(args):
    N = int(input())
    ans = solve(N)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])