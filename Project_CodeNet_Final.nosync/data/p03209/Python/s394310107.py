def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**7)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations, accumulate, groupby
    #from itertools import product
    from bisect import bisect_left,bisect_right
    from heapq import heapify, heappop, heappush
    from math import floor, ceil
    #from operator import itemgetter

    #inf = 10**17
    #mod = 10**9 + 7

    n,x = map(int, input().split())
    #b[i]:レベルiバーガーの層数(max:n)
    b = [1]
    for i in range(n):
        b.append(b[i]*2+3)

    #p[i]:レベルiバーガーのパティの数
    p = [1]
    for i in range(n):
        p.append(p[i]*2+1)

    #n:レベル　x:層数
    def solve(n, x):
        if n==0:
            if x==0:
                return 0
            else:
                return 1
        res = 0
        if b[n]//2 == x:
            res += p[n-1]
        elif b[n] == x:
            res += p[n-1]*2 + 1
        elif x == 0:
            res = 0
        elif b[n]//2 < x:
            res += p[n-1] + 1 + solve(n-1, x-b[n]//2-1)
        else:
            res += solve(n-1, x-1)
        return res

    print(solve(n, x))

if __name__ == '__main__':
    main()