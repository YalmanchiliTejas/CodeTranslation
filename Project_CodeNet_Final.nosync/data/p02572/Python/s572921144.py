from sys import stdin
nii=lambda:map(int,stdin.readline().split())
lnii=lambda:list(map(int,stdin.readline().split()))

n=int(input())
a=lnii()
total=sum(a)

mod=10**9+7

ans=0
for i in range(n-1):
  total-=a[i]
  ans+=a[i]*total
  ans%=mod

print(ans)