N=int(input())
a=sorted([int(input()) for i in range(N)])
r=[0]*N
r[1:-1:2]=a[:(N-1)//2]
r[-1]=a[(N-1)//2]
r[:-1:2]=a[(N-1)//2+1:]
A=list(reversed(a))
R=[0]*N
R[1:-1:2]=A[:(N-1)//2]
R[-1]=A[(N-1)//2]
R[:-1:2]=A[(N-1)//2+1:]
print(max(sum([abs(r[i]-r[i+1]) for i in range(N-1)]),sum([abs(R[i]-R[i+1]) for i in range(N-1)])))