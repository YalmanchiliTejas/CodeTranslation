n=int(input())
*a,=map(int, input().split())
mod=10**9+7

ans=sum(a)%mod
ans**=2

for ai in a:
    ans-=ai*ai
    ans%=mod

ans*=pow(2,mod-2,mod)
print(ans%mod)
