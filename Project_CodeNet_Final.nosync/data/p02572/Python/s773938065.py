MOD=10**9+7
N=int(input())
A=list(map(int,input().split()))
ans=sum(A)**2
ans-=sum(map(lambda x: x**2, A))
ans//=2
print(ans%MOD)