### ----------------
### ここから
### ----------------

import sys
from io import StringIO
import unittest
import copy

def yn(b):
    print("Yes" if b==1 else "No")
    return

def resolve():
    readline=sys.stdin.readline

    #n,m,k=map(int, readline().rstrip().split())
    mod=10**9+7
    n=int(readline())
    arr=list(map(int, readline().rstrip().split()))
    arr2=copy.copy(arr)
    for i in range(1,n):
        arr2[i]=(arr2[i]+arr2[i-1])%mod
    base=arr2[n-1]+mod
    ans=0
    for i in range(n-1):
        ans=(ans+arr[i]*((base-arr2[i])%mod))%mod
    print(ans)

    return

if 'doTest' not in globals():
    resolve()
    sys.exit()

### ----------------
### ここまで 
### ----------------