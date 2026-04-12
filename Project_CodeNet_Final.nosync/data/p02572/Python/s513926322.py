
n=int(input())
A=list(map(int,input().split()))
ans=0
mod=10**9+7
s=[0 for _ in range(n+1)]

for i in range(n):
    s[i+1]=(s[i]+A[i]%mod)%mod

for k in range(1,n):
    ans=(ans+(s[k]*(A[k]%mod))%mod)%mod
print(ans)