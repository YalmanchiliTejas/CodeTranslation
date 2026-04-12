from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    H, W = map(int, input().split())
    num = 0
    for _ in range(H):
        num += input().count("#")
    print("Possible" if num == H + W - 1 else "Impossible")


if __name__ == '__main__':
    main()
