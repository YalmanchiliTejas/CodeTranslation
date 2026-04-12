MOD=1000000007
N=int(input())
A=list(map(int,input().split()))
x=sum(A)%MOD
ans=x*x%MOD
ans+=sum(MOD-A[i]*A[i]%MOD for i in range(N))
ans%=MOD
ans*=500000004
ans%=MOD
print(ans)
