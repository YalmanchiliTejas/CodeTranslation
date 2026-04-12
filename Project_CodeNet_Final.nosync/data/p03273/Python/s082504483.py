import numpy as np
h,w=map(int,input().split())
a=[list(map(int,input().replace(".","0").replace("#","1"))) for i in range(h)]
a=np.array(a)
c=np.sum(a,axis=1)
a=a[c!=0]
c=np.sum(a,axis=0)
a=a.T[c!=0].T
for i in a.tolist():
    tmp=list((map(lambda x:"." if x==0 else "#",i)))
    print("".join(tmp))
    