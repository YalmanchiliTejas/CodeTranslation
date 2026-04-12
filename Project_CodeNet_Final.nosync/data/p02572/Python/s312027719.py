N=int(input())
A=list(map(int,input().split()))
mod=10**9+7
buf=0
s=0
for k in range(N-1):
    buf=(buf+A[N-1-k])%mod
    s=(s+A[N-2-k]*buf)%mod
print(s)
