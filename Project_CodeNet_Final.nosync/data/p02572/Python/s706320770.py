N=int(input())
A= list(map(int,input().split()))
ans=0
S=sum(A)
for i in range(N):
    S-=A[i]
    ans+=A[i]*S
print(ans%(10**9+7))