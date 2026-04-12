A=[1]*51
for i in range(1,51):
    A[i]=2*A[i-1]+3

def T(N,x):
    if N==0:
        return 1
    elif x==1:
        return 0
    elif 2<=x<=A[N-1]+1:
        return T(N-1,x-1)
    elif x==A[N-1]+2:
        return T(N-1,A[N-1])+1
    elif A[N-1]+3<=x<=2*A[N-1]+2:
        return T(N-1,A[N-1])+1+T(N-1,x-(A[N-1]+2))
    else:
        return 2*T(N-1,A[N-1])+1

N,X=map(int,input().split())
print(T(N,X))