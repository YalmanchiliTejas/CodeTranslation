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
    a = [list(input().rstrip()) for _ in range(h)]
    
    s = 0
    for i in range(h):
        for j in range(w):
            if a[i][j] == '#':
                if s != j:
                    print('Impossible')
                    exit()
                s +=  1
        s -= 1

    if s == w-1:
        print('Possible')
    else:
        print('Impossible')

if __name__ == '__main__':
    main()