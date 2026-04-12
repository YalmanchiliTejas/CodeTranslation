N,X=map(int,input().split())
def an(n):
    return 2**(n+1)-1
def bn(n):
    return 2**(n+2)-3
ans=0
while(N+1):
    if X==0:

        print(ans)
        quit()
    if X==bn(N):
        ans+=an(N)
        print(ans)
        quit()
    if X<=(bn(N)-1)/2:
        X-=1
        N-=1
    elif X==(bn(N)-1)/2+1:
        ans+=an(N-1)+1
        print(ans)
        quit()
    else:
        X=X-(bn(N-1)+2)
        ans+=an(N-1)+1
        N-=1
print(ans)

