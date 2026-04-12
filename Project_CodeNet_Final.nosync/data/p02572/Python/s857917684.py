n=int(input())
a=[0]+list(map(int,input().split()))
for i in range(n):
  a[i+1]+=a[i]
mod=10**9+7
ans=0
for i in range(1,n+1):
  ans+=(a[i]-a[i-1])*(a[-1]-a[i])%mod
  ans%=mod
print(ans)