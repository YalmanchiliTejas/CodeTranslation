n,k=map(int,input().split())

ans=0
for mod in range(1,n+1):
    ans+=(n//mod)*max(0,mod-k)
    ans+=max(0,n%mod-k+1) if k>0 else n%mod

print(ans)