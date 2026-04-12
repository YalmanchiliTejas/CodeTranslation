import sys
from math import *
from fractions import gcd
readints=lambda:map(int, input().strip('\n').split())

calc=[0]*55
calc[0]=1
for i in range(1,52):
    calc[i] = 3 + 2*calc[i-1]


n,x=readints()
x-=1 # 0-index


cache={}

def solve(L, i):
    if i<0:
        return 0
    if L==0:
        return 1
    else:
        if (L,i) in cache:
            return cache[(L,i)]
        m = calc[L] // 2
        res = 0
        if i>=m:
            res += solve(L-1,calc[L-1]-1) + 1
            res += solve(L-1,i-m-1)
            cache[(L,i)]=res
        else:
            cache[(L,i)]=solve(L-1, i-1)
        return cache[(L,i)]
        


print(solve(n,x))
