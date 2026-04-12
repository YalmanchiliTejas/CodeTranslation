# -*- coding: utf-8 -*-
"""
B - Grid Compression
https://atcoder.jp/contests/abc107/tasks/abc107_b

"""
import sys


def solve(H, W, grid):
    res = [row for row in grid if not(len(set(row)) == 1 and row[0] == '.')]
    return list(zip(*[row for row in list(reversed([list(m) for m in zip(*res)])) if not (len(set(row)) == 1 and row[0] == '.')][::-1]))


def main(args):
    H, W = map(int, input().split())
    grid = [list(input()) for _ in range(H)]
    ans = solve(H, W, grid)
    for row in ans:
        print(''.join(row))


if __name__ == '__main__':
    main(sys.argv[1:])
