n=int(input())
a= list(map(int, input().split()))


mod=pow(10,9)+7

b=[0]*(n+1)
b[-1]=0
for i in range(n):
    b[n-1-i]=(a[n-1-i]+b[n-i])%mod

ans=0
for i in range(n-1):
    ans+=a[i]*b[i+1]%mod
ans%=mod
print(ans)