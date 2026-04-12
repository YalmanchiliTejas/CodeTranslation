N=int(input())
a=list(map(int,input().split()))
ans=float("inf")
for r in range(0,N+1):
    test=0
    for j in range(0,N):
        test+=(a[j]+r+1)//(N+1)
    test-=r
    t=max(test,0)*(N+1)+r
    ans=min(ans,t)

print(ans)
