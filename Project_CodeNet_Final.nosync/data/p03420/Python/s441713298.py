import sys
n,k=map(int,input().split())
if k==0:
    print(n**2)
    sys.exit()
ans=0
for i in range(k+1,n+1):
    ans+=(n//i)*(i-k)
    if n%i>=k:
        ans+=n%i-k+1
print(ans)