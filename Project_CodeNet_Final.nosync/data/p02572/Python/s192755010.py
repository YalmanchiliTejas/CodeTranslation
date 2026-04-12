n=int(input())
a=list(map(int,input().split()))

A=sum(a)
ans=0
for i in range(n):
  A-=a[i]
  ans+=A*a[i]
print(ans%(10**9+7))