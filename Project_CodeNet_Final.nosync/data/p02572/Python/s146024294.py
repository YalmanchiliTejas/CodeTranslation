import numpy
n=int(input())
l=list(map(int, input().split()))
res=0
mod=10**9+7
l.append(0)
l.reverse()
cum=numpy.cumsum(l)%mod
for i in range(n):
    res+=((l[n-i]%mod)*cum[n-i-1])%mod
print(res%mod)