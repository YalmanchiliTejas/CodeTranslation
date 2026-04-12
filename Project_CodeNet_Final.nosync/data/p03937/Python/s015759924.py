# -*- coding: utf-8 -*-
"""
A - Shik and Stone
https://atcoder.jp/contests/agc007/tasks/agc007_a

"""
import sys


def solve(H, W, grid):
    x, y = 0, 0
    while True:
        grid[y][x] = '@'
        if x+1 < W and grid[y][x+1] == '#':
            x += 1
        elif y+1 < H and grid[y+1][x] == '#':
            y += 1
        else:
            break
    for row in grid:
        if '#' in row:
            return 'Impossible'
    return 'Possible'


def main(args):
    H, W = map(int, input().split())
    grid = [list(input()) for _ in range(H)]
    ans = solve(H, W, grid)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
