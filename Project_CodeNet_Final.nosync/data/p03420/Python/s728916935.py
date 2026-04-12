n,k=map(int,input().split())
ans=0
for i in range(1,n+1):
	c=(n+1)//i
	d=(n+1)%i
	ans+=max(0,i-k)*c+max(0,d-k)
if k==0:
	ans-=n
print(ans)