n,k=map(int,input().split())
ans=0
for b in range(k+1,n+1):
    ans+=min(n,(b-k)*(n//b)+max(0,n%b-k+1))
print(ans)
