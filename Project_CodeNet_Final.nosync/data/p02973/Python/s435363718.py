import sys
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

from bisect import bisect_left, bisect_right  # 二分探索
from heapq import heapify, heappush, heappop, heappushpop  # プライオリティキュー

def main():
    N = i2n()
    A = ii2nn(N)
    B = [1]
    for a in A:
        t = bisect_right(B, -a)
        if t < len(B):
            B[t] = -a
        else:
            B.append(-a)
    print(len(B))

main()
