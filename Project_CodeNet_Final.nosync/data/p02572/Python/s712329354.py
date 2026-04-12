n=int(input())
a=list(map(int,input().split()))
ans=0
t=sum(a)
s=0
for i in range(n):
  s+=a[i]*a[i]

ans=(t*t-s)//2
ans=ans%(10**9+7)



print(ans)