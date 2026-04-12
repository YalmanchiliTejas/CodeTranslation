import numpy as np
H,W=map(int,input().split(" "))

def white(a):
    ans=0
    for i in range(len(a)):
        if a[i]=="#":
            ans=1
    return ans

A=[]
for i in range(H):
    gyo=list(input())
    if white(gyo)==1:
        A.append(gyo)

Anum=np.array(A)
ash=Anum.shape[1]
for i in range(ash):
    j=ash-i-1
    if white(Anum[:,j])==0:
        Anum=np.delete(Anum,j,1)

for i in range(Anum.shape[0]):
    moji=""
    for j in range(Anum.shape[1]):
        moji+=Anum[i,j]        
    print(moji)
