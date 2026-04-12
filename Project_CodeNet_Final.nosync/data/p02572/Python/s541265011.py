N=int(input())
MOD=10**9+7
A=[int(x) for x in input().split()]
sumA=sum(A)
ans=0
for i in range(N):
    now=A[i]
    sumA-=now
    ans+=now*sumA
    ans%=MOD

print(ans)