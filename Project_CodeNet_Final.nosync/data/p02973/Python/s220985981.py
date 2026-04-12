'''
https://atcoder.jp/contests/abc134/tasks/abc134_e
'''
def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10000000)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations, accumulate
    #from itertools import product
    from bisect import bisect_left,bisect_right
    import heapq
    from math import floor, ceil
    #from operator import itemgetter

    #inf = 10**17
    #mod = 10**9 + 7

    N = int(input())
    A = [int(input()) for _ in range(N)]
    d = deque()
    for i in A:
        pos = bisect_left(d, i)
        if pos == 0:
            d.appendleft(i)
        else:
            d[pos-1] = i
    print(len(d))

if __name__ == '__main__':
    main()