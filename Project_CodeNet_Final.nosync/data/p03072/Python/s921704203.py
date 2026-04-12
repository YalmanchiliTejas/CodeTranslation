import sys
from bisect import *
from collections import *
from copy import deepcopy
from datetime import *
from heapq import *
from itertools import *
# from math import *
from operator import *
from pprint import *

sys.setrecursionlimit(10**8)

input = sys.stdin.readline

def main():
    """ main """
    N = int(input())
    HS = list(map(int, input().split()))
    ans = 1
    last = HS[0]
    for h in HS[1:]:
        if h >= last:
            last = h
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()