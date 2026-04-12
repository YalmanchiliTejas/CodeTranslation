n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
asum=0
for i in range(n):
    asum+=a[i]
    asum%=mod
ans=0
#print(asum)
for i in range(n):
    asum-=a[i]
    ans+=asum*a[i]
    ans%=mod
print(ans)