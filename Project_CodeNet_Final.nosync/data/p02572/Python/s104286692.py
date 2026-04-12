n=int(input())
mod1,mod2=10**9+7,998244353
mod=mod1
ans=0
s=0
for i in map(int,input().split()):
    ans=(ans+s*i)%mod
    s=(s+i)%mod
print(ans)