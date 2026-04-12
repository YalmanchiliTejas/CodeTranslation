n=int(input())
l=list(map(int,input().split()))
 
sum_l=sum(l)
ans=0
mod=10**9+7
 
for i in range(n):
  sum_l-=l[i]
  ans+=l[i]*sum_l
  
print(ans%mod)