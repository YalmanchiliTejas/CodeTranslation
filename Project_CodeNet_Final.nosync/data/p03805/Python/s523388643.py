import math
#import numpy as np
import itertools
import queue
from collections import deque,defaultdict
import heapq as hpq
from sys import stdin,setrecursionlimit
#from scipy.sparse.csgraph import dijkstra
#from scipy.sparse import csr_matrix
ipt = stdin.readline
setrecursionlimit(10**7)

def main():
    n,m = map(int,ipt().split())
    way = [[] for i in range(n+1)]
    ans = 0
    for i in range(m):
        a,b = map(int,ipt().split())
        way[a].append(b)
        way[b].append(a)
    for i in itertools.permutations(list(range(2,n+1))):
        p = 1
        f = True
        for j in i:
            if not j in way[p]:
                f = False
                break
            else:
                p = j
        if f:
            ans += 1
    print(ans)

    return None

if __name__ == '__main__':
    main()
