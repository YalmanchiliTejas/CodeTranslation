n=int(input())
a=list(map(int,input().split()))
t=sum(a)
ta=[0]*n
for i in range(n):
  ta[i]=t
  t=t-a[i]
ans=0
for i in range(0,n-1):
  ans=ans+(a[i]*ta[i+1])
  ans=(ans)%(10**9+7)
print(ans)