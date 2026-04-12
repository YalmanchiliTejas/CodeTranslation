from __future__ import print_function
# import numpy as np
# import numpypy as np
import sys
input = sys.stdin.readline

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    return

import math
import string
import fractions
from fractions import Fraction
from fractions import gcd

def lcm(n,m):
    return int(n*m/gcd(n,m))

import re
import array
import copy
import functools
import operator

import collections
import itertools
import bisect
import heapq


from heapq import heappush
from heapq import heappop
from heapq import heappushpop
from heapq import heapify
from heapq import heapreplace

from queue import PriorityQueue as pq

def reduce(p, q):
    common = fractions.gcd(p, q)
    return (p//common , q//common )
# from itertools import accumulate
# from collections import deque

import random


def main():
    H,W = map(int, input().strip().split()) # H行 W列
    G=[]
    for i_row in range(H):
        G.append(input().strip())
    eprint("graph G:")
    eprint(G)

    l_flag_row_all_dot_flag=[ 1 for _ in range(H) ]
    for i_row in range(H):
        for j_col in range(W):
            if G[i_row][j_col]!=".":
                l_flag_row_all_dot_flag[i_row]=0


    l_flag_col_all_dot_flag=[ 1 for _ in range(W) ]
    for j_col in range(W):
        for i_row in range(H):
            if G[i_row][j_col]!=".":
                l_flag_col_all_dot_flag[j_col]=0

    for i_row in range(H):
        if l_flag_row_all_dot_flag[i_row]==1:
            continue
        for j_col in range(W):
            if l_flag_col_all_dot_flag[j_col]==1:
                continue
            print(G[i_row][j_col],end="")
        print()






    # for i_row in range(H):      # H is length of row
    #     if G[i_row] == str(["."* W ]):
    #         G.pop(i_row)

    # all_dot_flag=1
    # for j_col in range(W):      # W は列の長さ
    #     for i_row in range(H):  # H は行の長さ
    #         G[i_row][j_col] != "."
    #         failure_flag=0
    #     if all_dot_flag==1:
    #         for ii in range(H):
    #             G.pop()
    return

if __name__ == '__main__':
    main()
