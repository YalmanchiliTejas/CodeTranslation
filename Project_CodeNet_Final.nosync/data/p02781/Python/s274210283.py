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

    #inf = 10**17
    #mod = 10**9 + 7

    n = input().rstrip()
    k = int(input())
    ln = len(n)
    # dp[i][j]:左からi桁まで見たとき0でない桁がj個ある場合の数
    dp1 = [[0]*(k+1) for _ in range(ln+1)]
    dp2 = [[0]*(k+1) for _ in range(ln+1)]

    dp2[0][0] = 1
    cnt = 0
    for i in range(ln):
        if n[i] != '0':
            if cnt < k:
                cnt += 1
            dp2[i+1][cnt] = 1
        else:
            dp2[i+1][cnt] = dp2[i][cnt]

    for i in range(ln):
        dp1[i+1][0] = 1
        for j in range(1, k+1):
            dp1[i+1][j] += dp1[i][j] + dp1[i][j-1] * 9
            if n[i] != '0':
                dp1[i+1][j] += dp2[i][j-1] * (int(n[i])-1)
                if j < k:
                    dp1[i+1][j] += dp2[i][j]
    print(dp1[-1][k] + dp2[-1][k])

if __name__ == '__main__':
    main()