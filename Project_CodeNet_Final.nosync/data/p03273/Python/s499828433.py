import sys
from collections import *
import heapq
import math
import bisect
import copy
from itertools import permutations,accumulate,combinations,product
from fractions import gcd
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]

h,w=map(int,input().split())
a=[input() for i in range(h)]

while 1:
    flag=1
    lst=[]
    for i in range(h):
        tmp=a[i][0]
        if tmp=="#":
            continue
        for j in range(w):
            if tmp==a[i][j]:
                continue
            else:
                break
        else:
            lst.append(i)
            flag=0
    for i in range(len(lst)):
        del a[lst[-1-i]]
        h-=1

    lst=[]
    for i in range(w):
        tmp=a[0][i]
        if tmp=="#":
            continue
        for j in range(h):
            if tmp==a[j][i]:
                continue
            else:
                break
        else:
            lst.append(i)
            flag=0
    # print(lst)
    # print(a)
    for i in range(len(lst)):
        for j in range(h):
            a[j]=a[j][:lst[-1-i]] + a[j][lst[-1-i]+1:]
    w-=len(lst)
    if flag:
        break
for i in a:
    print(i)