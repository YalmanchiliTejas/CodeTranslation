n,s=map(int,input().split())
now=[0]*(s+1)
mod1,mod2=10**9+7,998244353
mod=mod2

ans=0
for a in map(int,input().split()) :
    
    now[0]+=1
    for i in range(s,-1,-1):
        now[i]=(now[i]+(0 if i<a else now[i-a]))%mod
    ans=(ans+now[-1])%mod

print(ans)