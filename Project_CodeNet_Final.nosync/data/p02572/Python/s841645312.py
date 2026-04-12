import numpy as np
n=int(input())
a=list(map(int,input().split()))
suma = 0
mod = 10**9+7
sumall = sum(a)%mod
for i in range(n-1):
    sumall -= a[i]
    suma+= (a[i]*sumall)%mod
print(suma%mod)