n=int(input())
a=[int(x) for x in input().split()]
ruiseki=[0]
for i in range(1,n+1):
  ruiseki.append(ruiseki[i-1]+a[i-1])

ruiseki=ruiseki[1:]
mod=10**9+7
ma=max(ruiseki)
ans=0
for i in range(len(a)):
  ans+=((ma-ruiseki[i])*a[i])%mod
print(ans%mod)

