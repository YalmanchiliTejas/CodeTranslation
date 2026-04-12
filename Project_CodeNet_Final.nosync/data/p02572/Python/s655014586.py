n=int(input())
l=list(map(int,input().split()))
mod=10**9+7
ans=pow(sum(l)%mod,2,mod)
for i in range(n):
    ans-=l[i]**2
    ans%=mod
ans*=pow(2,mod-2,mod)
print(ans%mod)