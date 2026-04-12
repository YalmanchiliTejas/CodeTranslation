'''
自宅用PCでの解答
'''
import math
#import numpy as np
import itertools
import queue
import bisect
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)
mod = 10**9+7 #998244353
dir = [(-1,0),(0,-1),(1,0),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"

def main():
    n = int(ipt())
    a = [int(i) for i in ipt().split()]
    sm = sum(a)%mod
    ans = (sm**2)%mod
    for i in a:
        ans -= i**2
        ans %= mod

    print((ans*500000004)%mod)

    return None

if __name__ == '__main__':
    main()
