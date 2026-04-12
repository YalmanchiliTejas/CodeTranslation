n,k=map(int,input().split())
if k==0:
  ans=n*n
else:
  ans=0
  for i in range(k,n+1):
    ans+=(i-k)*(n//i)
    if n%i>=k:
      ans+=(n%i)-k+1
print(ans)