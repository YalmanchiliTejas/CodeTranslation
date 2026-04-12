N = int(input())
A = list(map(int, input().split()))
if N%2:
    a, b, c = 0, 0, 0
    for i in range(0,N-2,2):
        c=max(a+A[i+2],b+A[i+2],c+A[i+2])
        b=max(a+A[i+1],b+A[i+1])
        a+=A[i]
    print(max(a,b,c))
else:
    a, b = 0, 0
    for i in range(0,N-1,2):
        b=max(a+A[i+1],b+A[i+1])
        a+=A[i]
    print(max(a,b))