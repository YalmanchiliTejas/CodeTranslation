MOD=10**9+7
N=int(input())
A=list(map(int,input().split()))

cnt=A[-1]
sumA=[cnt]
for i in range(N-2,0,-1):
  sumA.append(sumA[-1]+A[i])

ans=0
for i in range(N-1):
  ans+=(A[i]*sumA[-i-1])
print(ans%MOD)