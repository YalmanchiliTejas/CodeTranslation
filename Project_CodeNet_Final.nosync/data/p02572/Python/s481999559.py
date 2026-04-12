
N=int(input())
A=list(map(int,input().split()))

mod=10**9+7

sumA=sum(A)

ans=0
for i in range(N):
    ans+=(A[i]*(sumA-A[i]))

ans=ans//2
print(ans%mod)
        