n=int(input())
a=list(map(int, input().split()))
mod=10**9+7
c=[0]*n
c[0]=a[0]
for i in range(1,n):
    c[i]=c[i-1]+a[i]
ans=0
for i in range(n-1):
    tmp=(c[-1]-c[i])*a[i]%mod
    ans=(ans+tmp)%mod
print(ans)