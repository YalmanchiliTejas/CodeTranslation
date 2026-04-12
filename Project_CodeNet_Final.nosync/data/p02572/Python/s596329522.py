MOD=10**9+7
N=int(input())
A=list(map(int,input().split()))
S=sum(A)
ans=0
for i in range(N-1):
  S-=A[i]
  ans+=(A[i]*S)%MOD
print(ans%MOD)