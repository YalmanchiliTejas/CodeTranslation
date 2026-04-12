n=int(input())
mod=10**9+7
a=[int(x) for x in input().split()]
a.sort(reverse=True)
ruiseki=[a[0]]
for i in range(1,n):
  ruiseki.append(a[i]+ruiseki[i-1])

ans=0
ruiseki.sort(reverse=True)

a.sort()
for i in range(1,n):
  ans+=((a[i-1])*ruiseki[i])%mod

print(ans%mod)
