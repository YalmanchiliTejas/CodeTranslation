import sys
N=int(sys.stdin.readline().strip())
A=map(int, sys.stdin.readline().split())
mod=10**9+7
RUISEKI=[0]
for a in A:
    RUISEKI.append((RUISEKI[-1]+a)%mod)

ans=0
for i in range(N):
    ans+=A[i]*(RUISEKI[-1]-RUISEKI[i+1])
    ans%=mod
print ans
