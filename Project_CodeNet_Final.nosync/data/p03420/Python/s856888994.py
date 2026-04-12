n,k=map(int,input().split())
b=[i for i in range(k+1,n+1)]
ans=0
if k==0:
    for i in range(len(b)):
        t=b[i]
        j=t-k
        ii=n//t
        ans+=ii*j
        ans+=max(n-ii*t-k,0)
    print(ans)
    exit()
for i in range(len(b)):
    t=b[i]
    j=t-k
    ii=n//t
    ans+=ii*j
    ans+=max(n-ii*t-k+1,0)
print(ans)