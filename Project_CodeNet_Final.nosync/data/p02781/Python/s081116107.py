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
    N,K = map(int, read().split())
    k = int(math.log(N, 10))
    s = N // (10 ** k)

    tmp1, tmp2, div = 1, 1, 1
    for i in range(K-1):
        tmp1 *= k-i
        div *= i+1
        tmp2 *= 9
    ret = tmp1//div * tmp2
    ret *= s-1

    tmp1 *= k - (K-1)
    tmp2 *= 9
    div *= K

    ret += tmp1 * tmp2 // div
    lis = range(k)
    nums = range(1,10)
    base = s * 10 ** k

    for A in combinations(lis, K-1):
        for X in product(nums, repeat = K-1):
            tmp = base
            for a,x in zip(A,X):
                tmp += 10 ** a * x
            if tmp <= N:
                ret += 1
    print(ret)



if __name__ == "__main__":
    run()