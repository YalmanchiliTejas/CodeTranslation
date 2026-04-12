# -*- coding: utf-8 -*-
"""
A - Can you get AC?
https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_a

"""
import sys


def solve(S):
    if 'AC' in S:
        return 'Yes'
    return 'No'


def main(args):
    S = input()
    ans = solve(S)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
