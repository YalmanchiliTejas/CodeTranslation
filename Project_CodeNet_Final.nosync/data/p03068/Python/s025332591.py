# -*- coding: utf-8 -*-
"""
B - *e**** ********e* *e****e* ****e**
https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_b

"""
import sys


def solve(N, S, K):
    ch = S[K-1]
    ans = [['*', s][ch==s] for s in S]
    return ''.join(ans)


def main(args):
    N = int(input())
    S = input()
    K = int(input())
    ans = solve(N, S, K)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
