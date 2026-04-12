import numpy as np

h,w = map(int,input().split())

a = np.empty(0,dtype=np.unicode)
for i in range(h):
    a = np.append(a,[x for x in input()])

a = np.reshape(a,(h,w))
a = a[:,np.any(a == '#',axis=0)]
a = a[np.any(a == '#',axis=1)]

a = a.tolist()
for i in a:
    print("".join(i))
