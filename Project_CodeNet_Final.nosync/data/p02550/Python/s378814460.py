import sys
import math
import itertools
import collections
from collections import deque
from collections import defaultdict

sys.setrecursionlimit(1000000)
MOD = 10 ** 9 + 7
MOD2 = 998244353
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

NI = lambda: int(input())
NMI = lambda: map(int, input().split())
NLI = lambda: list(NMI())
SI = lambda: input()

def main():
    N, X, M = NMI()
    
    tmp = X%M
    
    ls = []
    ls.append(tmp)
    
    for n in range(N-1):
        tmp = (tmp ** 2)%M
        
        if tmp in ls:
            ls_before_loop = ls[:ls.index(tmp)]
            ls_in_loop = ls[ls.index(tmp):]
            break
        else:
            ls.append(tmp)


    
    if len(ls) == N:
        print(sum(ls))
    else:
        sum_before_loop = sum(ls_before_loop)
        sum_in_loop = ((N-len(ls_before_loop))//(len(ls_in_loop)))*sum(ls_in_loop)
        sum_after_loop = sum(ls_in_loop[:(N-((N-len(ls_before_loop))//(len(ls_in_loop)))*len(ls_in_loop))-len(ls_before_loop)])
        print(sum_before_loop+sum_in_loop+sum_after_loop)


if __name__ == '__main__':
    main()