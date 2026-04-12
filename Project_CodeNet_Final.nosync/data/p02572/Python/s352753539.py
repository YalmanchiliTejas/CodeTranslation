n=int(input())
a=[int(x) for x in input().split()]
m=10**9+7
s=sum(a)
ans=0
for i in range(n-1):
  s-=a[i]
  ans+=a[i]*s
  ans%=m
ans%=m
print(ans)