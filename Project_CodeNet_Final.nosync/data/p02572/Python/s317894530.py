n=int(input())
lst=list(map(int,input().split()))
val=sum(lst)
prev=0
ans=0
for i in lst:
  prev+=i
  ans+=i*(val-prev)
print(ans%1000000007)