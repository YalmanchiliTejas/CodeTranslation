# coding: utf-8
import sys
#from operator import itemgetter
sysread = sys.stdin.readline
read = sys.stdin.read
#from heapq import heappop, heappush
#from collections import defaultdict
sys.setrecursionlimit(10**7)
import math
from itertools import combinations, product
#import bisect# lower_bound etc
#import numpy as np
def run():
    N,K = read().split()

    N = list(map(int,N))
    K = int(K)
    max_i = len(N)
    dp2 = [0] * max_i
    r = 0
    for i, v in enumerate(N):
        if v != 0:
            r += 1
        dp2[i] = r

    dp1 = [[0] * (K+1) for _ in range(max_i)]

    dp1[0][1] = int(N[0]-1)
    dp1[0][0] = 1
    for i in range(1, max_i):
        for j in range(0, K+1):
            if j == 0:
                dp1[i][j] += dp1[i - 1][j]
            else:
                dp1[i][j] += dp1[i - 1][j] + dp1[i - 1][j - 1] * 9
        if N[i] == 0:continue
        if dp2[i-1] <= K:
            dp1[i][dp2[i-1]] += 1
        if dp2[i-1] < K:
            dp1[i][dp2[i-1]+1] += N[i] - 1
    plus = 0
    if dp2[-1] == K:
        plus = 1
    print(dp1[max_i-1][K] + plus)




if __name__ == "__main__":
    run()