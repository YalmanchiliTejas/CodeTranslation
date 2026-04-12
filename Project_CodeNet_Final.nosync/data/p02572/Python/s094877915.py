N=int(input())
A=list(map(int,input().split()))

mod=10**9+7

B=[0]
for i in range(1,N+1):
    B.append(A[i-1]+B[i-1])

ans=0
for i in range(N-1):
    ans+=A[i]*(B[N]-B[i+1])
    ans%=mod

print(int(ans))