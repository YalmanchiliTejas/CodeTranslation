N,X,M=map(int,input().split())

A=[0,X]
D={}
D[X]=1
for i in range(2,10**7):
    A.append((A[-1]**2)%M)
    if A[-1] not in D:
        D[A[-1]]=i
    else:
        R=i
        L=D[A[-1]]
        break
    
#print(A)
#print(D)
#print(L,R)
    
Front=L-1

if N<=Front:
    print(sum(A[:N+1]))
    exit()
N-=Front
X=N//(R-L)
Y=N%(R-L)
#print(Y)
if Y>0:
    print(sum(A[:Front+1])+X*sum(A[L:R])+sum(A[L:L+Y]))
else:
    print(sum(A[:Front+1])+X*sum(A[L:R]))
#print(sum(A[:Front+1]),sum(A[L:R+1]))