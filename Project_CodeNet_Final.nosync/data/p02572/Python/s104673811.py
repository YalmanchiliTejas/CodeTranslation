n=int(input())
A=list(map(int,input().split()))
a=sum(A)
a=a**2
b=0

for j in range(n):
  b+=A[j]**2
if a-b<0:
  c=a-b
  while c<=0:
    c+=mod
  
  ans=c//2
  ans=ans%(10**9+7)
 
else:
  ans=(a-b)//2
  ans=ans%(10**9+7)
 
print(ans)