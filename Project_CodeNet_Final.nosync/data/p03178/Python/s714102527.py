import numpy as np
k=input()
d=int(input())
m=10**9+7
t=np.zeros(d)
s=0
for i in k:
    p=np.zeros(d)
    for j in range(10):
        p+=np.hstack([t[-(j%d):],t[:-(j%d)]])
    for j in range(int(i)):
        p[(s+j)%d]+=1
    t=p[::]%m
    s+=int(i)
t[s%d]+=1
print((int(t[0])-1)%m)