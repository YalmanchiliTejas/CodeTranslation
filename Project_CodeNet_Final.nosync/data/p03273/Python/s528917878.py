import sys, os, math, bisect, itertools, collections, heapq, queue
# from scipy.sparse.csgraph import csgraph_from_dense, floyd_warshall
from decimal import Decimal
from collections import defaultdict, deque

sys.setrecursionlimit(10000000)

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]

lcm = lambda x, y: (x * y) // math.gcd(x, y)

MOD = 10 ** 9 + 7
MAX = float('inf')


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    H, W = il()
    HW = [sl() for _ in range(H)]
    h = [False] * H
    w = [False] * W

    for n in range(H):
        hw = HW[n]
        if '#' in hw[0]:
            h[n] = True
        for m in range(W):
            if hw[0][m] == '#':
                w[m] = True

    for n in range(H):
        if h[n]:
            str = ''
            for m in range(W):
                if w[m]:
                    str += HW[n][0][m]
            print(str)


if __name__ == '__main__':
    main()
