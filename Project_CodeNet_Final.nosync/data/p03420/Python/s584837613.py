n,k=map(int,input().split())

if k==0:
    print(n**2)
else:
    ans=0
    for b in range(1,n+1):
        ans+=n//b*max(0,b-k)
        ans+=max(0,n%b-k+1)
    print(ans)
