# -*- coding: utf-8 -*-
"""
C - One-stroke Path
https://atcoder.jp/contests/abc054/tasks/abc054_c

"""
import sys


from itertools import permutations

def solve(N, M, path):
    ans = 0
    for p in permutations(range(2, N+1)):
        p = [1] + list(p)
        for f, t in zip(p, p[1:]):
            if not [f, t] in path and not [t, f] in path:
                break
        else:
            ans += 1
    return ans


def main(args):
    N, M = map(int, input().split())
    path = [[int(i) for i in input().split()] for _ in range(M)]
    ans = solve(N, M, path)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
