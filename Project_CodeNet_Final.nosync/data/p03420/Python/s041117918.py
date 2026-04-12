n,k=map(int,input().split())
ans=0
if k==0:
    print(n*n)
    exit()
for i in range(k+1,n+1):
    ans+=(i-k)*(n//i)
    if n-i*(n//i)-k+1>0:
        ans+=n-i*(n//i)-k+1
    # print(ans,i)
print(ans)