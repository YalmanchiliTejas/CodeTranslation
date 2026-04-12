n,k=map(int,input().split())

ans=0
for i in range(k+1,n+1):
    ans+=n//i*(i-k)
    if n%i>0:
        if k==0:
            ans+=n%i
        else:
            ans+=max(0,n%i-k+1)
    #print(ans)

print(ans)