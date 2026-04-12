import math
import collections
import itertools

def resolve():
    N=int(input())
    A=list(map(int,input().split()))

    B=[0]*N
    B[N-1]=A[N-1]
    MOD=10**9+7
    for j in range(N-2,0,-1):
        B[j]=(B[j+1]+A[j])%MOD
   
    ans=0
    for i in range(N-1):
        ans=ans%MOD+(A[i]*B[i+1])%MOD

    print(ans%MOD)

resolve()
