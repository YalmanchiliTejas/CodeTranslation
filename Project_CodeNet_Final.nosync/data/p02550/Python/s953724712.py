# -*- coding: utf-8 -*-

N,X,M=map(int,input().split())

A=[0]*10**5
A[0]=X
D=dict()
#A=[X]
s=N
for i in range(1,N):
    a=A[i-1]**2%M
    if a in D:
        s=A.index(a)
        break
    else:
        #A.append(a)
        A[i]=a
        D[a]=0

if s==N:
    ans=sum(A)
else:
    A=A[:i]
    Z=[0]*(len(A)+1)
    for i in range(1,len(A)+1):
        Z[i]=Z[i-1]+A[i-1]  

    ans=0
    l=len(A)-s
    #ans+=sum(A[:s])
    ans+=Z[s]
    #S=sum(A[s:])
    S=Z[len(A)]-Z[s]
    T=(N-s)//l
    ans+=T*S
    K=N-s-l*T
    #ans+=sum(A[s:(s+K)])
    ans+=Z[s+K]-Z[s]


print(ans)
