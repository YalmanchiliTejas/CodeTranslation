MOD=10**9+7

N=int(input())
A=list(map(int, input().split()))
X=[0]*N
X[0]=A[0]+0
X[0]%=MOD
for i in range(1, N):
  X[i]=X[i-1]+A[i]
  X[i]%=MOD
  
ans=0
for i in range(1, N):
  tmp=X[i-1]*A[i]%MOD
  ans=(ans+tmp)%MOD
print(ans)