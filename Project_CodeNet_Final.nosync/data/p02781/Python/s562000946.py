"""
E
"""
import sys
from operator import mul
from functools import reduce
def cmb(n,r):
    r=min(n-r,r)
    if r==0:
        return 1
    over=reduce(mul,range(n,n-r,-1))
    under=reduce(mul,range(1,r+1))
    return over//under


N=list(input())
N=list(map(int,N))
K=int(input())

L=len(N)
if L<K:
    print(0)
    sys.exit()
ans=0
if L>K:
    ans+=cmb(L-1,K)*(9**K)
ans+=(N[0]-1)*cmb(L-1,K-1)*(9**(K-1))


if K==1:
    ans=(L-1)*9+N[0]
    
elif K==2:
    H=[0]*L
    H[0]=N[0]
    for i in range(1,L):
        for j in range(1,10):
            H[i]=j
            if N>=H:
                ans+=1
        H[i]=0
    
else:
    H=[0]*L
    H[0]=N[0]
    for i in range(1,L-1):
        for k in range(1,10):
            H[i]=k
            for j in range(i+1,L):
                for l in range(1,10):
                    H[j]=l
                    if N>=H:
                        ans+=1
                H[j]=0
        H[i]=0
print(ans)