# -*- coding: utf-8 -*-
import sys
import math
import numpy as np
from itertools import permutations
from functools import reduce
# sys.setrecursionlimit(10000)


def main():
    # 入力処理
    N, M = map(int, input().split())
    edges = [set(map(int, input().split())) for i in range(M)]
    print(edges, file=sys.stderr)

    # アルゴリズム本体
    ps = permutations(range(2,N+1), N-1)

    C = 0
    for p in ps:
        q = [1] + list(p)
        xs = [set((q[i],q[i+1])) in edges for i in range(N-1)]
        if all(xs):
            print(q, file=sys.stderr)
            C += 1

    # 出力
    print(C)


if __name__ == '__main__':
    main()
