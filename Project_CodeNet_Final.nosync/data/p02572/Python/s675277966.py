N=int(input())
A=list(map(int,input().split()))

MOD=10**9+7
sumA=0
for i in range(N):
    sumA=(sumA+A[i])%MOD

ans=0
for i in range(N-1):
    sumA=(sumA-A[i])%MOD
    ans=(ans+(A[i]*sumA)%MOD)%MOD

print(ans)