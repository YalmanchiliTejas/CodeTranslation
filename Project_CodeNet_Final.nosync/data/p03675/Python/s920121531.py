import math
import numpy as np

n=int(input())
a=np.array([int(i)  for i in input().split()])

b=np.zeros(n, dtype=int)
pos=math.ceil((n-1)/2)

forward=True
for i in range(n):
    #print("i:{0}, pos:{1}, a[i]:{2}".format(i, pos, a[i]))
    b[pos]=a[i]
    if forward:
        forward=False
        pos-=(i+1)
    else:
        forward=True
        pos+=(i+1)
        
if forward:
    for i in range(n):
        print(b[i],end=' ')
else:
    for i in range(n):
        print(b[n-1-i],end=' ')