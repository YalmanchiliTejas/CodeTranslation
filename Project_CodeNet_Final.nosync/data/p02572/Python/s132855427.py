n=int(input())
a=list(map(int,input().split()))
ans=0
suma=sum(a)
for i in range(n):
  suma-=a[i]
  ans+=(a[i]*(suma))%(10**9+7)
print(int(ans%(10**9+7)))
