# -*- coding: utf-8 -*-
"""
http://abc064.contest.atcoder.jp/tasks/abc064_a

"""
import sys
from sys import stdin
input = stdin.readline


def main(args):
    r, g, b = map(int, input().split())
    num = (r * 100) + (g * 10) + b
    if num % 4 == 0:
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main(sys.argv[1:])