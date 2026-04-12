K=input()
N=len(K)
D=int(input())
import numpy as np
d=np.zeros((N+1,D),dtype=np.int64)
d2=np.zeros((N+1,D),dtype=np.int64)
d[0,0]=1
m=10**9+7
r=(D+9)//D
for i in range(N):
    dc=d[i]
    dc2=d2[i]
    for j in range(r):
        dc=np.concatenate((dc,d[i]))
        dc2=np.concatenate((dc2,d2[i]))
    dc,dc2=np.cumsum(dc),np.cumsum(dc2)
    x=int(K[i])
    d[i+1]=np.roll(d[i],x)
    d2[i+1]=(dc[r*D:]-dc[r*D-x:(r+1)*D-x]+dc2[r*D:]-dc2[r*D-10:(r+1)*D-10])%m
print((d[-1,0]+d2[-1,0]-1)%m)