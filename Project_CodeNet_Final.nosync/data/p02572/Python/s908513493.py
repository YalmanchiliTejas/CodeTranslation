n=int(input())
a=list(map(int,input().split()))
a.reverse()
l=[0]*n
l[0]=a[0]
for i in range(n-1):
  l[i+1]=l[i]+a[i+1]
ans=0
mod=10**9+7
for j in range(1,n):
  ans+=(a[j]*l[j-1])%mod
print(ans%mod)