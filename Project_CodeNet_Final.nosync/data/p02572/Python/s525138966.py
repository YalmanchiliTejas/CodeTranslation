n=int(input())
mod=10**9+7
a=list(map(int,input().split()))

A=sum(a)%mod
total=0

for i in range(n-1):
    A-=a[i]
    total+=A*a[i]
    total%=mod

print(total)