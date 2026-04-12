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

    h,w = map(int, input().split())
    a = [list(input().rstrip()) for _ in range(h)]
    tate = []
    yoko = []
    for i in range(h):
        if '#' not in a[i]:
            yoko.append(i)
    for i in range(w):
        for j in range(h):
            if a[j][i] == '#':
                break
        else:
            tate.append(i)
    res = []
    for i in range(h):
        temp = []
        if i in yoko:
            continue
        for j in range(w):
            if j in tate:
                continue
            temp.append(a[i][j])
        res.append(temp)
    for i in res:
        print(''.join(i))

if __name__ == '__main__':
    main()