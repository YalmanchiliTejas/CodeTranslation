n,k=map(int,input().split())
ans=0
for i in range(k+1,n+1):
  ans+=n//i*(i-k)
  if n//i*i+k<=n:ans+=n+1-(n//i*i+k)
print([ans,n**2][k==0])