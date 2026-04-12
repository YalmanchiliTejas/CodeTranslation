import sys
import copy
#import math
#import itertools
#import numpy as np
#import re

def func(x,m):
    return x**2%m

N,X,M=[int(c) for c in input().split()]
myset = {X}
mydict = {X:0}
A = []
A.append(X)
s = X
i = 0
i_stop = i
#i=0は計算したので1から
for i in range(1,N):
    A.append(func(A[i-1],M))
    if A[i] in myset:
        i_stop = i
        break
    myset.add(A[i])
    mydict[A[i]] = i
    s+=A[i]
    if i == N-1:
        print(s)
        sys.exit(0)
    if A[i] == 0:
        print(s)
        sys.exit(0)

if i!=0:
    #最後にA[i]が出現したのは？
    A_repeat = A[mydict[A[i_stop]]:i_stop]
    s+=((N-1)-(i_stop-1))//len(A_repeat)*sum(A_repeat)

    for k in range(((N-1)-(i_stop-1))%len(A_repeat)):
        s+=A_repeat[k]

print(s) 