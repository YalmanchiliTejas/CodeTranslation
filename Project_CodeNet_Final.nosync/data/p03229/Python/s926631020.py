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

def main():
    n = int(ipt())
    a = [int(ipt()) for i in range(n)]
    a.sort()
    if n%2:
        ans = a[n//2+1]-a[n//2-1]
        for i in range(n//2-1):
            ans += (a[n-1-i]-a[i])*2
        print(ans+max(a[n//2+1]-a[n//2],a[n//2]-a[n//2-1]))
    else:
        ans = a[n//2]-a[n//2-1]
        for i in range(n//2-1):
            ans += (a[n-1-i]-a[i])*2
        print(ans)
    return None

if __name__ == '__main__':
    main()
