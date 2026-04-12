N=int(input())
A=[0]+[int(i) for i in input().split()]
S=[0]*(N+1)
MOD=10**9+7
for i in range(1,N+1):
    S[i]=(S[i-1]+A[i])%MOD

ans=0
for i in range(2,N+1):
    ans=(ans+A[i]*S[i-1])%MOD

print(ans)
