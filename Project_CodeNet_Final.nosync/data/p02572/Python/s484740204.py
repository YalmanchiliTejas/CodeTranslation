n=int(input())
a=list(map(int,input().split()))
p=10**9+7
ans=0
k=sum(a)-a[0]
for i in range(n-1):
  ans+=(k*a[i])%p
  ans%=p
  k-=a[i+1]
print(ans)