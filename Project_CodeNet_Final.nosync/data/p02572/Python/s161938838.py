n=int(input())
A=[0]+list(map(int, input().split()))
mod=10**9 + 7
S=sum(A)
ans=0

for i in range(1, n):
    ans+=A[i]*(S-A[i])
    ans%=mod
    S-=A[i]

print(ans)