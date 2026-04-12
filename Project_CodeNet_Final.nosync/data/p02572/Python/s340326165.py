N=int(input())
A=list(map(int,input().split()))

M=sum(A)%(10**9+7)
C=0
for i in range(N-1):
    M=M-A[i]
    C+=(A[i]*M)
    C=C%(10**9+7)

print(C)