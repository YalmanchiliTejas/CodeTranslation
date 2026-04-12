n=int(input())
a=list(map(int,input().split()))
asum=[0]*n
MOD=10**9+7
ai=0
for i in range(n-1,-1,-1):
    ai+=a[i]
    ai%=MOD
    asum[i]=ai
ans=0
for i in range(n-1):
    ans+=a[i]*asum[i+1]
    ans%=MOD
print(ans)