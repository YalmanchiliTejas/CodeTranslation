N=int(input())
A=list(map(int,input().split()))
mod=10**9+7
a=sum(A)
ans=0
for i in range(N):
    a-=A[i]
    ans+=a*A[i]
    ans%=mod
print(ans)