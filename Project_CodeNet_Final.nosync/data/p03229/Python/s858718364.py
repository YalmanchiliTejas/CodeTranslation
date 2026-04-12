N=int(input())
A=[int(input()) for i in range(N)]

A.sort()

k1=[]
if N%2==1:
    k1.extend([1,1])
    k1.extend([-2]*(N//2))
    k1.extend([2]*(N-N//2-2))
    k1.sort()
    sum1=0
    sum2=0
    for i in range(N):
        sum1+=A[i]*k1[i]
        sum2+=(-1)*A[i]*k1[-1-i]
    print(max(sum1,sum2))
else:
    k1.extend([-1,1])
    k1.extend([-2]*((N-2)//2))
    k1.extend([2]*((N-2)//2))
    k1.sort()
    sum1=0
    sum2=0
    for i in range(N):
        sum1+=A[i]*k1[i]
        sum2+=(-1)*A[i]*k1[-1-i]
    print(max(sum1,sum2))