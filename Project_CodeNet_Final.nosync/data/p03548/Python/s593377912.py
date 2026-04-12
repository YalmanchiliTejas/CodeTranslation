def main():
    import sys
    #input = sys.stdin.readline
    sys.setrecursionlimit(10000000)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations
    #from itertools import accumulate, product, permutations
    from math import floor, ceil

    #mod = 1000000007

    x,y,z = map(int, input().split())
    print((x-z)//(y+z))
        

if __name__ == '__main__':
    main()