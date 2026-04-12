import numpy as np
I,S=input,sum
n,c=int(I()),0
a=np.array(list(map(int, I().split())))
while max(a)>=n:f=a//n;S=sum(f);a=a-f*n+(S-f);c+=sum(f)
print(c)