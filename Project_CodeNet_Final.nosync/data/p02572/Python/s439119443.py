n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
INf=float('inf')

Acc=[0]*(n+1)
for i in range(1,n+1):
  Acc[i]=(Acc[i-1]+A[i-1])%mod

ans=0  
for i in range(n):
  s=A[i]*(Acc[n]-Acc[i+1])
  ans+=s%mod

print(ans%mod)