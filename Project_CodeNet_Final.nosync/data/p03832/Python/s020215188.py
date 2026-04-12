n,a,b,c,d=map(int,input().split())
dp=[0]*(n+1)
dp[0]=1
mod=10**9+7
N=n
fac=[1]*(N+3)
inv=[1]*(N+3)
t=1
for i in range(1,N+3):
    t*=i
    t%=mod
    fac[i]=t
t=pow(fac[N+2],mod-2,mod)
for i in range(N+2,0,-1):
    inv[i]=t
    t*=i
    t%=mod
def comb(n,r):
    if r>n or r<0:
        return 0
    return fac[n]*inv[n-r]*inv[r]%mod

for i in range(a,b+1):
    for j in range(n,i*c-1,-1):
        for k in range(max(j-i*d,j%i),j-i*c+1,i):
            l=((j-k)//i)
            dp[j]+=dp[k]*fac[n-k]%mod*inv[n-j]*inv[l]%mod*pow(inv[i],l,mod)
            dp[j]%=mod
print(dp[-1])