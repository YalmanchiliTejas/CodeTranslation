n=int(input())
a=list(map(int, input().split()))
mod=10**9+7
k=a[n-1]
ans=(a[n-2]*k)%mod
for i in range(n-2, -1 ,-1):
    k+=a[i]
    k%=mod
    if (i):
        ans+=(a[i-1]*k)%mod
        ans%=mod
print(ans)
