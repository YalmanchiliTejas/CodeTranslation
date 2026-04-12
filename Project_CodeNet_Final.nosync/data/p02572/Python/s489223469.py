N=int(input())
A=list(map(int, input().split()))
p=10**9+7
S=sum(A)
S2=S**2
T=0
for i in range(N):
    T+=A[i]**2
ans=((S2-T)//2)%p
print(ans)
