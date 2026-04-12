import sys
from fractions import gcd
from itertools import permutations, combinations, accumulate
from collections import deque
from heapq import heappush, heappop, heapify
import math
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
MOD = 10**9 + 7

def main():
    n,m = list(map(int,input().split()))
    if n == m:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()