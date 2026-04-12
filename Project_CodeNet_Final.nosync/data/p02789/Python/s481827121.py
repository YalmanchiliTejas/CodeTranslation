# -*- coding: utf-8 -*-
import sys
from fractions import gcd
from string import ascii_lowercase as ABC
#input = sys.stdin.readline
def inpl(): return list(map(int, input().split()))
N, M = inpl()
if (N == M):
    print("Yes")
else:
    print("No")