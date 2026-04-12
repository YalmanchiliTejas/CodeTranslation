import sys
import math
from copy import deepcopy
from collections import deque, defaultdict
from operator import mul
from functools import reduce
sys.setrecursionlimit(20000000)

count = 0


def main():
    N, M = map(int, input().split())
    info = [list(map(int, input().split())) for _ in range(M)]
    g = deque(list())

    def visit(n, memo):
        n_memo = deepcopy(memo)
        n_memo.append(n)
        children = g[n]

        if len(n_memo) == N:
            global count
            count += 1

        for child in children:
            if child not in n_memo:
                visit(child, n_memo)

    for _ in range(N):
        g.append([])

    for p, c in info:
        g[p-1].append(c-1)
        g[c-1].append(p-1)

    visit(0, [])

    print(count)


if __name__ == '__main__':
    main()

