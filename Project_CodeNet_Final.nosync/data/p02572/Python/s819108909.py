N=int(input())
L=list(map(int,input().split()))
S=sum(L)

R=[S-L[0]]
for i in range(1,N):
    R.append(R[-1]-L[i])
#print(R)

mod=10**9+7
ans=0
for i in range(N):
    ans += L[i]*R[i]
    ans%=mod
print(ans)