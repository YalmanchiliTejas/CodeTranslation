import numpy as np
h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
np_a=np.array(a)
np_at=np_a.T
at=np_at.tolist()

r=[]
c=[]

for i in range(h):
    if a[i].count('#')==0:
        r.append(i)
for i in range(w):
    if at[i].count('#')==0:
        c.append(i)

for i in range(len(r)):
    del a[r[i]-i]
for j in range(len(c)):
    for i in range(h-len(r)):
        del a[i][c[j]-j]

for i in range(h-len(r)):
    print(''.join(a[i]))