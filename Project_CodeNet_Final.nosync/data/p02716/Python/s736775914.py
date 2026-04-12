N=int(input())
A=list(map(int,input().split()))
if N%2:
    a=[None]*N
    b=[None]*N
    c=[None]*N
    a[0]=A[0]
    b[1]=A[1]
    c[2]=A[2]
    for i in range(2,N-2,2):
        a[i]=a[i-2]+A[i]
    for i in range(3,N,2):
        b[i]=max(a[i-3],b[i-2])+A[i]
    for i in range(4,N,2):
        c[i]=max(a[i-4],b[i-3],c[i-2])+A[i]
    print(max(a[-3],b[-2],c[-1]))
else:
    a=[None]*N
    b=[None]*N
    a[0]=A[0]
    for i in range(2,N,2):
        a[i]=a[i-2]+A[i]
    b[1]=A[1]
    for i in range(3,N,2):
        b[i]=max(a[i-3],b[i-2])+A[i]
    print(max(a[-2],b[-1]))