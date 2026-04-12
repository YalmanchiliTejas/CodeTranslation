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
mod = 10**9+7
# mod = 998244353
dir = [(-1,0),(0,-1),(1,0),(0,1)]
alp = "abcdefghijklmnopqrstuvwxyz"
INF = 1<<32-1
# INF = 10**18

def main():
    n,x,m = map(int,ipt().split())
    rps = [x]
    ln = [-1]*m
    ln[x] = 0
    nn = x
    rs = 0
    rg = n
    for i in range(1,n):
        nn = (nn**2)%m
        if ln[nn] == -1:
            ln[nn] = i
            rps.append(nn)
        else:
            rs = ln[nn]
            rg = i
            break
    ans = sum(rps[:rs:])
    smsg = sum(rps[rs:rg:])
    rpl = rg-rs
    ans += (n-rs)//rpl*smsg
    ans += sum(rps[rs:rs+(n-rs)%rpl:])

    print(ans)

    return None

if __name__ == '__main__':
    main()
