# -*- coding: utf-8 -*-
"""
https://beta.atcoder.jp/contests/abc078/tasks/abc078_b

"""
import sys
from sys import stdin
input = stdin.readline


def main(args):
    X, Y, Z = map(int, input().split())
    ans = (X - Z) // (Y + Z)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
