n=int(input())
A=[int(i) for i in input().split()]
rui=A[0]
mod=10**9+7
ans=0
for i in range(1,n):
    ans+=rui*A[i]
    rui+=A[i]
    ans%=mod
    rui%=mod
print(ans)