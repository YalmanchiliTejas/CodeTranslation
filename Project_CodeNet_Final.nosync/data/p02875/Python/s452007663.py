
n=int(input())
pre=[1]*(n//2+200)
pp=[1]*(n+1)
mod=998244353
for i in range(1,n//2+100):
    pre[i]=((pre[i-1]*2)%mod)
    
p=[1]*(n+1)
for i in range(n):
    p[i+1]=((p[i]*(i+1))%mod)
pp[-1] = pow(p[-1], mod - 2, mod)
 
for i in range(2, n + 1):
	pp[-i] = int((pp[-i + 1] * (n + 2 - i)) % mod)
tot=1
for i in range(n):
    tot*=3
    tot%=mod
#print(1)
#print(tot)
cc=0
for i in range(n//2+1,n+1):
    c=(((((p[n]*pp[i])%mod)*pp[n-i])%mod)*pre[n-i])%mod
    c%=mod
    cc+=c
tot-=cc
tot-=cc
tot%=mod
print(tot)
