n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
from functools import reduce
S=reduce(lambda x,y:(x+y)%mod,A)
B=[]
for i in range(n):
    S=(S-A[i])%mod
    B.append(S)
N=0
for i in range(n):
    N=(N+A[i]*B[i])%mod
print(N)