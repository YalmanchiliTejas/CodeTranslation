import sys
from collections import Counter
import random
import numpy as np

n=int(input())
x=np.array(list(map(int,input().split())))
z=sorted(x)
cand=[z[n//2-1],z[n//2]]
#print(int(np.median(x)))
dic={}
for i in range(n):
    a=x[i]
    if(a<=cand[0]):print(cand[1])
    else:print(cand[0])