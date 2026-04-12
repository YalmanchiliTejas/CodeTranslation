n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
S=sum(A) % mod
r=0
for i in range(n-1):
    S-=A[i]%mod
    r+=S*A[i]%mod
print(r%mod)