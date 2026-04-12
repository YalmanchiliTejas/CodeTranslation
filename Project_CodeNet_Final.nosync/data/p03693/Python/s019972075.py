"""
author : halo2halo
date : 24,Oct,2019
"""

import sys
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 7)

a, b, c = map(int, readline().rstrip().split())

print("YES" if (a*100+b*10+c) % 4 == 0 else "NO")
