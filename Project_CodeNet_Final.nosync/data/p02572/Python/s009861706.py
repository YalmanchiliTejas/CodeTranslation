n=int(input())
a=list(map(int,input().split()))
score=0
mod=10**9+7
b=sum(a)
for i in range(0,n-1):
  b-=a[i]
  score+=a[i]*b

print(score%mod)