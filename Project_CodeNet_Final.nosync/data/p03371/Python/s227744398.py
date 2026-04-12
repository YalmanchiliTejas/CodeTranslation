import math
import itertools
import numpy as np

def solve():
    a, b, c, x, y = map(int, input().split())
    case1 = a * x + b * y
    case2 = x * 2 * c + max(0, (y - x) * b)
    case3 = max(0, (x - y) * a) +  y * 2 * c
    case4 = max(x, y) * 2 * c
    print(min(case1, case2,case3,case4))
    return 0

if __name__ == "__main__":
    solve()
