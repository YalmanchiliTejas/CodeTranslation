N=int(input())
A = list(map(int,input().split()))

A_acc=[sum(A)]
for a in A:
    A_acc.append(A_acc[-1]-a)

MOD=10**9+7

ans=0

for i in range(N-1):
    ans+=A_acc[i+1]*A[i]
    ans%=MOD
print(ans)


