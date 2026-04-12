# -*- coding: utf-8 -*-
"""
A - 居合を終え、青い絵を覆う / UOIAUAI
https://atcoder.jp/contests/abc049/tasks/abc049_a

"""
import sys


def solve(c):
    if c in 'aeiou':
        return 'vowel'
    return 'consonant'


def main(args):
    c = input()
    ans = solve(c)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])