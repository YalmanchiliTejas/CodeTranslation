MOD=10**9+7

N=int(input())
A=list(map(int,input().split()))
S=sum(A)**2%MOD
for i in range(N):
    S=(S-A[i]**2+MOD)%MOD
print(S*pow(2,MOD-2,MOD)%MOD)