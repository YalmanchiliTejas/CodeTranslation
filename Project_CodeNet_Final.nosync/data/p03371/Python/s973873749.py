# -*- coding: utf-8 -*-
"""
C - Half and Half
https://beta.atcoder.jp/contests/abc095/tasks/arc096_a

"""
import sys
from sys import stdin
input = stdin.readline


def solve(A, B, C, X, Y):
    if A + B <= 2 * C:
        return A * X + B * Y

    m = min(X, Y)
    ans = 2 * m * C

    Y -= m
    if 2 * C < B:
        ans += 2 * C * Y
    else:
        ans += B * Y

    X -= m
    if 2 * C < A:
        ans += 2 * C * X
    else:
        ans += A * X

    return ans


def main(args):
    A, B, C, X, Y = map(int, input().split())
    ans = solve(A, B, C, X, Y)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
