import sys
from itertools import product
import copy

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    H, W = map(int, input().split())
    A = [list(input()) for _ in range(H)]

    grid_init = [["." for _ in range(W)] for _ in range(H)]
    grid_init[0][0] = "#"
    for pattern in product(["L", "D"], repeat=H + W - 2):
        grid = copy.deepcopy(grid_init)
        if pattern.count("L") == W - 1 or pattern.count("D") == H - 1:
            h, w = 0, 0
            for p in pattern:
                if p == "L":
                    w += 1
                else:
                    h += 1
                grid[h][w] = "#"

            flg = True
            for h in range(H):
                for w in range(W):
                    if A[h][w] != grid[h][w]:
                        flg = False
                        break

            if flg:
                print("Possible")
                break
    else:
        print("Impossible")


if __name__ == '__main__':
    resolve()
