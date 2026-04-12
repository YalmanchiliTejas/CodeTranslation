import sys
read = sys.stdin.buffer.read
input = sys.stdin.buffer.readline
inputs= sys.stdin.buffer.readlines
#rstrip().decode('utf-8')

#import numpy as np
#import operator
#import bisect
#from heapq import heapify,heappop,heappush
#from math import gcd
#from fractions import gcd
#from collections import deque
#from collections import defaultdict
#from collections import Counter
#from itertools import accumulate
#from itertools import groupby
#from itertools import permutations
#from itertools import combinations
#scipy.sparse import csr_matrix
#scipy.sparse.csgraph import floyd_warshall
#from scipy.sparse.csgraph import csgraph_from_dense
#from scipy.sparse.csgraph import dijkstra
#sys.setrecursionlimit(10**7)

#map(int,input().split())

def main():
    N,K=map(int,input().split())
    ans=0
    for i in range(K+1,N+1):
        ans+=(N//i)*(i-K)+max((N%i-max(K,1)+1),0)
    print(ans)



if __name__ == '__main__':
    main()