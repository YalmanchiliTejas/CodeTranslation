import numpy as np
h,w=list(map(int,input().split()))
n=[list(input())for i in range(h)]
s=np.array(n)
s=s.T
s=s.tolist()
s=[t for t in s if t!=["."]*h]
k=len(s)
p=np.array(s)
p=p.T
p=p.tolist()
p=[t for t in p if t!=["."]*k]
for i in range(len(p)):
    h=p[i]
    d=len(h)
    c=""
    for j in range(d):
        c+=h[j]
    print(c)    