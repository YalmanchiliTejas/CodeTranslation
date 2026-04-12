n,k=map(int,input().split())
ans=0
for b in range(1,n+1):
  p=n//b
  r=n-p*b
  ans+=p*max(b-k,0)+max(0,r-k+1)
if k==0:
  ans-=n
print(ans)