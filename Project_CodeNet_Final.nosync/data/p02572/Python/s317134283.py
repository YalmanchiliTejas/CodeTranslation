n=int(input())
mod=10**9+7
A=list(map(int,input().split()))

a=sum(A)
a=(a**2)

b=0
for i in range(n):
  b+=(A[i])**2
if a-b<0:
  c=a-b
  while c<=0:
    c+=mod
  
  ans=c//2
  ans=ans%mod

else:
  ans=(a-b)//2
  ans=ans%mod

print(ans)