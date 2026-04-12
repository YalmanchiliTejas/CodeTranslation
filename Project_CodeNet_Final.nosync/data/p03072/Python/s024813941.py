def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**7)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations, accumulate, groupby, product
    from bisect import bisect_left,bisect_right
    from heapq import heapify, heappop, heappush
    import math
    #from math import gcd

    #inf = 10**17
    #mod = 10**9 + 7

    n = int(input())
    h = list(map(int, input().split()))
    res = 0
    m = 0
    for i in h:
        if i >= m:
            res += 1
            m = max(m, i)
    print(res)

if __name__ == '__main__':
    main()