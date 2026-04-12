# coding:utf-8

import sys


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


N = int(input())

if N == 7 or N == 5 or N == 3:
    print('YES')
else:
    print('NO')
