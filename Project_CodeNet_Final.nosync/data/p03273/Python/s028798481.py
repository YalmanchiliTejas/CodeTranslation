import numpy as np
h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
a=np.reshape(a,(h,w))
a=a[:,np.any(a=='#',axis=0)][np.any(a=='#',axis=1),:]
[print("".join(a[i])) for i in range(a.shape[0])]