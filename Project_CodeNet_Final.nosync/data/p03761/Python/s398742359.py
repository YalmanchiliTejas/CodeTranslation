# -*- coding: utf-8 -*-
"""
https://abc058.contest.atcoder.jp/tasks/arc071_a

"""
import sys
from sys import stdin
from collections import Counter
input = stdin.readline


def solve(S, n):
    freq = [[0]*n for _ in range(26)]

    for x, s in enumerate(S):
        c = Counter(s).most_common()
        for ch, f in c:
            y = ord(ch) - ord('a')
            freq[y][x] = f

    chars = []
    for i, ch in enumerate('abcdefghijklmnopqrstuvwxyz'):
        f = min(freq[i])
        for _ in range(f):
            chars.append(ch)
    return chars


def main(args):
    S = []
    n = int(input())
    for _ in range(n):
        s = list(input().strip())
        S.append(s)
    ans = solve(S, n)
    print(*ans, sep='')


if __name__ == '__main__':
    main(sys.argv[1:])
