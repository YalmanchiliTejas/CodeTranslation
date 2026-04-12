from collections import deque,defaultdict,Counter
from bisect import bisect_left,bisect_right,insort_left,insort_right
from heapq import heapify,heappop,heappush
from fractions import gcd
from copy import deepcopy
from itertools import accumulate,groupby,permutations,combinations
from math import ceil,sqrt,cos,sin,pi

def main():
    S = input()
 
    if S == "A"*3 or S == "B"*3:
        print("No")
    else:
        print("Yes")

if __name__ == '__main__':
    main()