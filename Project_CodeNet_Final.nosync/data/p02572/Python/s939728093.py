import os
import sys
from collections import defaultdict, Counter
from itertools import product, permutations,combinations, accumulate
from operator import itemgetter
from bisect import bisect_left,bisect
from heapq import heappop,heappush,heapify
from math import ceil, floor, sqrt
from copy import deepcopy
 

def cumsum(xs):
    pass

def main():
    n = int(input())
    alist = list(map(int, input().split()))
    max_num = 10**9 + 7
    ans = 0
    sum_num = sum(alist)

    for i in range(n-1):
        sum_num -= alist[i]
        ans += alist[i] * sum_num
        

    print(ans%max_num)

if __name__ == "__main__":
    main()