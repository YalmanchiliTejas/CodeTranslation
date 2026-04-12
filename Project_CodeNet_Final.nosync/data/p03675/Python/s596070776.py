N=int(input())

A=list(map(int,input().split()))
B=[]
C=[]

for i in range(N):
    if(N%2==0):
        if(i%2==0):
            B.append(A[i])
        else:
            C.append(A[i])
    else:
        if(i%2==0):
            C.append(A[i])
        else:
            B.append(A[i])

C.reverse()
for i in range(len(B)):
    C.append(B[i])

for i in range(N):
    print(C[i] if i==0 else " "+str(C[i]),end="")
print()
