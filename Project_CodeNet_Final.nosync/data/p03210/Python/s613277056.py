def main():
    from builtins import int, str, map, list, dict, float, print, len, sorted, max, min
    from itertools import accumulate, permutations, combinations
    from collections import deque, defaultdict, Counter
    from operator import itemgetter
    from bisect import bisect_left, bisect_right, bisect
    from heapq import heappop, heappush
    from fractions import gcd
    import sys, re, math, copy
    sys.setrecursionlimit(10 ** 6)

    input = sys.stdin.readline
    input_list = (lambda: input().rstrip().split())
    input_number = (lambda: int(input()))
    input_number_list = (lambda: list(map(int, input_list())))

    N = input_number()
    print('YNEOS'[not N in [3,5,7]::2])


if __name__ == '__main__':
    main()
