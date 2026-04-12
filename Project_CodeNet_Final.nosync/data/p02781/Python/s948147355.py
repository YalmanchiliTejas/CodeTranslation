N=int(input())
K=int(input())

from operator import mul
from functools import reduce

def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

L=len(str(N))
ans=0
if L-1>=K:
    ans=cmb(L-1,K)*(9**K)

List=[]
for i in range(1,10):
    List.append(i*10**(L-1))

import sys
if K==1:
    for i in List:
        if i<=N:
            ans+=1
        else:
            print(ans)
            sys.exit()
    print(ans)
elif K==2:
    for i in List:
        for j in range(L-1):
            for k in range(1,10):
                T=i+k*10**j
                if T<=N:
                    ans+=1
                else:
                    print(ans)
                    sys.exit()
    print(ans)
elif K==3:
    for i in List:
        for j in range(L):
            for k in range(j+1,L-1):
                T=i+9*10**j+9*10**k
                if T<=N:
                    ans+=81
                else:
                    for l in range(1,10):
                        for m in range(1,10):
                            T=i+m*10**j+l*10**k
                            if T<=N:
                                ans+=1
                            else:
                                continue
    print(ans)
else:
    print(0)