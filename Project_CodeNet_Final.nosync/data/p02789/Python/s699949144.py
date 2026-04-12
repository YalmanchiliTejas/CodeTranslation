# import numpy as np
# import math
# import copy
# from collections import deque
import sys
input = sys.stdin.readline
# sys.setrecursionlimit(10000)


def main():
    N,M = map(int,input().split())
    if N == M:
        res = 'Yes'
    else:
        res = 'No'
    print(res)



main()
