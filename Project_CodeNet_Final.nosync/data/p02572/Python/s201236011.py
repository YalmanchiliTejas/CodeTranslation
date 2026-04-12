n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
t=0
for i in range(n):
    t=(t+a[i])%mod
s=t*t%mod
m=0
for i in range(n):
    m=(m+(a[i]**2)%mod)%mod
d=pow(2,mod-2,mod)
ans=((s-m)%mod)*d
print(ans%mod)