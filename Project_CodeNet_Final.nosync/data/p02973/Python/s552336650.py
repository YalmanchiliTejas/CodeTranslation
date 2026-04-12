import math
import bisect
from collections import deque
import sys
input = sys.stdin.readline


def Solve():
    L=[]
    N=int(input())
    for i in range(N):
        L.append(int(input()))

    col=1
    K=deque()
    
    
    for i,a in enumerate(L):
        if i==0:
            K.append(a)
            continue
        pos=bisect.bisect_left(K,a)
        if pos==0:
            col+=1
            K.appendleft(a)
        else:
            K[pos-1]=a

    return col



print(Solve())

