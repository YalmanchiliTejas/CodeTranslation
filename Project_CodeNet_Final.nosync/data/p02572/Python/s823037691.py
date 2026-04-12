N=int(input())
A=list(map(int, input().split()))
Acum=[0]*(N+1)
for i in range(0,N):
    Acum[i+1]=Acum[i]+A[i]
ans=0
for i in range(N-1):
    ans+=A[i]*(Acum[N]-Acum[i+1])
print(ans%(10**9+7))