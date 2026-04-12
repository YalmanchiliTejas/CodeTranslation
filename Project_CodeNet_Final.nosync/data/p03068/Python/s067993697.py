def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**7)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations, accumulate, groupby, product
    from bisect import bisect_left,bisect_right
    from heapq import heapify, heappop, heappush
    from math import floor, ceil
    #from operator import itemgetter

    #inf = 10**17
    #mod = 10**9 + 7

    n = int(input())
    s = list(input().rstrip())
    k = int(input())
    a = s[k-1]
    for i in range(n):
        if s[i] == a:
            continue
        s[i] = '*'
    print(*s, sep='')

if __name__ == '__main__':
    main()