#import math
#import itertools
#import numpy as np
#from collections import deque
# sys.setrecursionlimit(10 ** 6)
#MOD = 10 ** 9 + 7
#INF = 10 ** 9
#PI = 3.14159265358979323846

INT = lambda: int(input())
INTM = lambda: map(int,input().split())
STRM = lambda: map(str,input().split())
STR = lambda: str(input())
LIST = lambda: list(map(int,input().split()))
LISTS = lambda: list(map(str,input().split()))

def do():
    n,x,m=INTM()
    bool=[False]*m
    mod=[]
    temp=x
    for i in range(m+1):
        if bool[temp]:
            break
        else:
            bool[temp]=True
            mod.append(temp)
            temp=(temp*temp)%m
    b=mod.index(temp)
    if b>0:
        sumt=sum(mod[0:b])
        mod=mod[b:]
    else:
        sumt=0
    lm=len(mod)
    sumr=0
    if (n-b)%lm!=0:
        sumr=sum(mod[0:(n-b)%lm])
    print(sumt+sumr+sum(mod)*((n-b)//lm))

if __name__=='__main__':
    do()