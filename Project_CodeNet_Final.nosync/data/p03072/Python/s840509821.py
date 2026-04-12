import sys
from collections import deque  # 双方向キュー
from collections import defaultdict  # 初期化済み辞書
from heapq import heapify, heappush, heappop, heappushpop  # プライオリティキュー
from bisect import bisect_left, bisect_right  # 二分探索
#import numpy as np  # 1.8.2
#import scipy  # 0.13.3
#sys.setrecursionlimit(int(1e+6))
s2nn = lambda s: [int(c) for c in s.split(' ')]
ss2nn = lambda ss: [int(s) for s in ss]
ss2nnn = lambda ss: [s2nn(s) for s in ss]
i2s = lambda: sys.stdin.readline().rstrip()
i2n = lambda: int(i2s())
i2nn = lambda: s2nn(i2s())
ii2ss = lambda n: [sys.stdin.readline().rstrip() for _ in range(n)]
ii2sss = lambda n: [list(sys.stdin.readline().rstrip()) for _ in range(n)]
ii2nn = lambda n: ss2nn(ii2ss(n))
ii2nnn = lambda n: ss2nnn(ii2ss(n))
MOD = int(1e+9) + 7

def main():
    N = i2n()
    H = i2nn()
    n = 1
    h = H[0]
    for i in range(1, N):
        if H[i] >= h:
            h = H[i]
            n += 1
    print(n)

main()
