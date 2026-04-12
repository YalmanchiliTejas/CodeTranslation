from statistics import median
N=int(input())
A=[]
for i in range(N):
    A.append(int(input()))
med=median(A)
A=[abs(int(i)-med) for i in A]
A=sorted(A)
ans=0
ans+=sum(A[:2]+2*A[2:])
print(int(ans))