
n=int(input())
a=list(map(int,input().split()))

mod=10**9+7

s=[0]*n
s[0]=a[0]
for i in range(1,n):
    s[i]=(s[i-1]+a[i])%mod

ss=0
for i in range(n-1):
    ss+=((s[n-1]-s[i])*a[i])%mod

print(ss%mod)
