N=int(input())
A=[int(input()) for _ in range(N)]

A.sort()
B=[]
C=[]
if N%2==1:
    m=A[N//2]
    ans=0
    for i in range(N//2):
        B.append(A[i])
        C.append(A[-1-i])
        B.append(A[-1-i])
        C.append(A[i])
    dB=abs(m-B[0])
    dC=abs(m-C[0])
    for j in range(1,len(B)):
        dB+=abs(B[j]-B[j-1])
        dC+=abs(C[j]-C[j-1])
    ans=max(dB,dC)
else:
    for i in range(N//2):
        B.append(A[i])
        C.append(A[-1-i])
        B.append(A[-1-i])
        C.append(A[i])
    dB=abs(B[-1]-B[0])
    dC=abs(C[-1]-C[0])
    for j in range(1,len(B)-1):
        dB+=abs(B[j]-B[j-1])
        dC+=abs(C[j]-C[j-1])
    ans=max(dB,dC)
print(ans)