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
    a = list(map(int, input().split()))
    dp = [[0]*N for _ in range(N)]
    if N%2 == 0:
        for l in range(N-1, -1, -1):
            for r in range(N):
                if l > r:
                    continue
                if l==r==N-1 or l==r==0:
                    dp[l][N-r-1] = -a[l]
                if l+1==N or N-r-1+1==N:
                    continue
                if (r-l+1)%2 == 0:
                    dp[l][N-r-1] = max(dp[l+1][N-r-1]+a[l], dp[l][N-r-1+1]+a[r])
                else:
                    dp[l][N-r-1] = min(dp[l+1][N-r-1]-a[l], dp[l][N-r-1+1]-a[r])
    else:
        for l in range(N-1, -1, -1):
            for r in range(N):
                if l > r:
                    continue
                if l==r==N-1 or l==r==0:
                    dp[l][N-r-1] = a[l]
                if l+1==N or N-r-1+1==N:
                    continue
                if (r-l+1)%2 == 0:
                    dp[l][N-r-1] = min(dp[l+1][N-r-1]-a[l], dp[l][N-r-1+1]-a[r])
                else:
                    dp[l][N-r-1] = max(dp[l+1][N-r-1]+a[l], dp[l][N-r-1+1]+a[r])
    print(dp[0][0])
    
if __name__ == '__main__':
    main()