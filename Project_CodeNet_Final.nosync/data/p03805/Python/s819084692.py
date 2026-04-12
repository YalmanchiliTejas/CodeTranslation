import itertools
L=["2","3","4","5","6","7","8"]

N,M=map(int,input().split())

L=L[:N-1]
A=list(itertools.permutations(L,N-1))
C=[]
for i in A:
    B=["1"]+list(i)
    C.append(B)
#print(C)
D={}
for i in range(M):
    a,b=input().split()
    D[(a,b)]=1
    D[(b,a)]=1
    
#print(D)

ans=0
for i in C:
    f=1
    for j in range(N-1):
        if (i[j],i[j+1]) not in D:
            f=0
            break
    if f==1:
        ans+=1
print(ans)