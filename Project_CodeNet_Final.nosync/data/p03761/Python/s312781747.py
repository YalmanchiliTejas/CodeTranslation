from collections import Counter
n=int(input())
D={}
SC=Counter(input())
for k,v in SC.items():
    D[k]=v
for i in range(n-1):
    temp={}
    C=Counter(input())
    for k in D.keys():
        if k in C:
            temp[k]=min(D[k],C[k])
    D=temp
L=[]
for k,v in D.items():
    for i in range(v):
        L.append(k)
print(''.join(sorted(L)))