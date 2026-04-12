# -*- coding: utf-8 -*-

import sys
import copy

sys.setrecursionlimit(1000000)

# input = sys.stdin.readline

# ~~~~~~~~~~~~~~~~~~~~~_(＾～＾ ｣ ∠)_~~~~~~~~~~~~~~~~~~~~~

N = int(input())
S = input()
K = int(input())

c = S[K - 1]

ans = ""
for a in S:
    ans += c if a == c else '*'


print(ans)
