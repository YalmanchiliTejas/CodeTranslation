import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
# from math import *
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
import copy
import time
# import numpy as np
starttime = time.time()
# import numpy as np
mod = int(pow(10, 9) + 7)
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def L(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]

try:
    # sys.setrecursionlimit(int(pow(10,5)))
    sys.stdin = open("input.txt", "r")
    # sys.stdout = open("../output.txt", "w")
except:
    pass



n,x,m=L()
A=[x]
d={}
k=1
d[x]=1
while(A[-1]!=0 and k<n):
    y=A[-1]*A[-1]%m
    if y in d:
        break
    else:
        d[y]=1
    A.append(y)
    k+=1
if A[-1]==0:
    print(sum(A))
elif k==n:
    print(sum(A))
elif k<n:
    # print(n,k,A,y)

    # idx=A.index(y)
    # # print(idx)
    # ans=sum(A[:idx])
    # z=A[idx:]
    # # print(z)
    # ans+=sum(z)*(n-idx)//len(z)
    # total=idx+((n-idx)//len(z))*len(z)
    # rem=n-total
    # ans+=sum(z[:rem])

    # print(ans)
    pref=0
    ans=0
    rem=-2
    cnt=-1
    # print(A[:10])
    for i in range(len(A)):
        if A[i]==y:
            ans+=pref
            pref=0
            cnt=0
            rem=(n-i)%(len(A)-i)
            # print(ans)
        if rem==cnt:
            ans+=pref
        if cnt>=0:
            cnt+=1
        pref+=A[i]
    ans+=pref*((n-k+cnt)//(cnt))
    print(ans)

endtime = time.time()
# print(f"Runtime of the program is {endtime - starttime}")

