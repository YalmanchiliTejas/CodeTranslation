n,k=map(int,input().split())
ans=0
if k==0:
    ans=n**2
else:
    for i in range(k+1,n+1):
        num2=i-k
        ans+=(n//i)*num2
        ans+=max(0,(n%i)-k+1)
print(ans)
