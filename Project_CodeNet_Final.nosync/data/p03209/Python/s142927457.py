N,X=list(map(int, input().split()))
A=[0]*(N+1)
P=[0]*(N+1)
A[0]=1
P[0]=1

for i in range(N):
    A[i+1]=2*A[i]+3
    P[i+1]=2*P[i]+1
# print(A)
# print(P)

def burguer(n,x):
    if x==0:
        return 0
    if x==A[n]:
        return P[n]
    if x<=A[n-1]+1:
        y=burguer(n-1,x-1)
        return y
    else:
        y=burguer(n-1,x-A[n-1]-2)
        return P[n-1]+1+y

print(burguer(N,X))