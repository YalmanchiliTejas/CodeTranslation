N=int(input())
A=list(map(int,input().split()))
ans=0
tmp=0
for i in range(N):
    tmp+=A[i]
    
for i in range(N):
    tmp-=A[i]
    ans+=A[i]*tmp%(10**9+7)
    ans%=(10**9+7)
print(ans)
