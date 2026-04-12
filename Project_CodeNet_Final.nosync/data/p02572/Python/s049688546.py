n=int(input())
a=list(map(int,input().split()))
ans=0
wa=sum(a)
for i in range(n):
  wa-=a[i]
  ans=(ans+(wa*a[i]))%(10**9+7)
print(ans)