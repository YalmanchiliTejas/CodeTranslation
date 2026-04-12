mod=10**9+7
N=int(input())
A=list(map(int,input().split()))
B=[0 for i in range(N)]
B[0]=sum(A)-A[0]
count=(A[0]*B[0])%mod
for i in range(1,N):
    B[i]=B[i-1]-A[i]
    count=(count+A[i]*B[i])%mod
print(count)