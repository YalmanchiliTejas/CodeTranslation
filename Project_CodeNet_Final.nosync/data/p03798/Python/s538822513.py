#始めの2匹が決まるとあとは自動的に決まるので矛盾していないかどうか判定

def main():
    import sys
    #input = sys.stdin.readline
    sys.setrecursionlimit(10000000)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations
    #from itertools import accumulate, product
    from bisect import bisect_left,bisect_right
    from math import floor, ceil
    #from operator import itemgetter

    #mod = 1000000007

    N = int(input())
    s = list(input())
    s += s[0]

    def check(p):
        for i in range(1, N+1):
            if s[i]=='o' and p[i]=='S':
                p += p[i-1]
            elif s[i]=='o' and p[i]=='W':
                if p[i-1]=='S':
                    p += 'W'
                else:
                    p += 'S'
            elif s[i]=='x' and p[i]=='S':
                if p[i-1]=='S':
                    p += 'W'
                else:
                    p += 'S'
            else:
                p += p[i-1]
        if p[0]==p[N] and p[1]==p[N+1]:
            print(p[:-2])
            exit()

    for i in ['SS', 'SW', 'WS', 'WW']:
        check(i)
    print(-1)

if __name__ == '__main__':
    main()