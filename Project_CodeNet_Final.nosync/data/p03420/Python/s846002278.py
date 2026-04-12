n,k=map(int,input().split())
if k==0:
    print(n**2)
    exit(0)
ans=0
for i in range(k+1,n+1):
    q,r=divmod(n,i)
    ans+=q*(i-k)
    if r>=k:
        ans+=max(r-k+1,0)
print(ans)

