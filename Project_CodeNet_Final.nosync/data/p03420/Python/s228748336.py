n,k=map(int,input().split())
ans=0
for b in range(k+1,n+1):
  m=(n//b)
  mm=n%b
  ans+=m*(b-k)
  ans+=max(0,mm-k+1)
print(ans-(n if k==0 else 0))