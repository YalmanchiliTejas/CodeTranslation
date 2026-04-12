import numpy as np
h,w=map(int,input().split())
a=np.array([[0 if x=='.' else 1 for x in input()] for _ in range(h)])
f=True
while(f):
    f=False
    i=0
    while(i<a.shape[0]):
        if np.sum(a[i])==0:
            f=True
            a=np.delete(a,i,0)
        i+=1
    i=0
    while(i<a.shape[1]):
        if np.sum(a[:,i])==0:
            f=True
            a=np.delete(a,i,1)
        i+=1
a=[list(x) for x in list(a)]
a=[['.' if x==0 else '#' for x in a[i]] for i in range(len(a))]
for i in range(len(a)):
    print(''.join(a[i]))
