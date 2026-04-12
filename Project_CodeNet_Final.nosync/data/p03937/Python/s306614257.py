# '#'の数がH+W-1

def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**7)
    from collections import Counter, deque
    from itertools import combinations, permutations, accumulate, groupby, product
    from bisect import bisect_left,bisect_right
    from heapq import heapify, heappop, heappush
    import math
    #from math import gcd

    #inf = 10**17
    #mod = 10**9 + 7

    h,w = map(int, input().split())
    s = 0
    for _ in range(h):
        a = input().rstrip()
        s += a.count('#')

    if s == h+w-1:
        print('Possible')
    else:
        print('Impossible')

if __name__ == '__main__':
    main()