'''
研究室PCでの解答
'''
import math
#import numpy as np
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
dir = [(-1,0),(1,0),(0,-1),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"

def main():
    n = int(ipt())
    ans = [-int(ipt())]
    for i in range(n-1):
        a = -int(ipt())
        if a >= ans[-1]:
            ans.append(a)
        else:
            ans[bisect.bisect_right(ans,a)] = a
#        print(ans)
    print(len(ans))

    return None

if __name__ == '__main__':
    main()
