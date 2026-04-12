n=int(input())
a=list(map(int, input().split()))
s=sum(a)
ans=0
for i in range(n):
  ans+=a[i]*(s-a[i])
print(ans//2%(10**9+7))