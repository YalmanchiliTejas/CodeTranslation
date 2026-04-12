# -*- coding: utf-8 -*-
"""
B - Great Ocean View
https://atcoder.jp/contests/abc124/tasks/abc124_b

"""
import sys


def solve(N, heights):
    max_height = -1
    res = []
    for h in heights:
        res.append(h >= max_height)
        max_height = max(max_height, h)
    return sum(res)


def main(args):
    N = int(input())
    heights = [int(h) for h in input().split()]
    ans = solve(N, heights)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
