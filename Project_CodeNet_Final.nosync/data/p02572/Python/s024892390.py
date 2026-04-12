mod=10**9+7

N=int(input())
A=list(map(int,input().split()))
B=[0]
for x in A:
  B.append(B[-1]+x)

ans=0
for i in range(N):
  s=(B[N]-B[i+1])%mod
  ans+=A[i]*s
  ans%=mod

print(ans)
