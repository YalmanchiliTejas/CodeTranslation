n,k=map(int,input().split())
ans=0
if k==0:
    print(n**2)
    exit()
for b in range(k+1,n+1):
    num=b-k
    l=n//b
    m=n%b
    ans+=num*l
    ans+=max(0,m-k+1)
print(ans)