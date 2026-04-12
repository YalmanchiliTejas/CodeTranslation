n=int(input())
ans=0
mod=10**9+7
list1=list(map(int ,input().split()))
sums=sum(list1)

for i in list1:
  sums -=i
  ans +=sums*i%mod
  
print(ans%mod)