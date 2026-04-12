N=int(input())
A=list(map(int,input().strip().split()))
s=sum(A)
ans=0
MOD=10**9+7
for n in range(N):
    s-=A[n]
    ans+=(A[n]*s)%MOD
print(ans%MOD)