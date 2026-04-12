# coding: utf-8
# hello worldと表示する
#float型を許すな
#numpyはpythonで
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
from collections import Counter, deque
from collections import defaultdict
from itertools import combinations, permutations, accumulate, groupby, product
from bisect import bisect_left,bisect_right
from heapq import heapify, heappop, heappush
from math import floor, ceil,pi,factorial,sqrt
from operator import itemgetter
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))
def LI2(): return [int(input()) for i in range(n)]
def MXI(): return [[LI()]for i in range(n)]
def SI(): return input().rstrip()
def printns(x): print('\n'.join(x))
def printni(x): print('\n'.join(list(map(str,x))))
inf = 10**17
mod = 10**9 + 7

n=I()
s=SI()
def nex(i):
    if i==n-1:
        i=-1
    if lis[i]==1:
        if s[i]=="o":
            if lis[i-1]==1:
                lis[i+1]=1
            else:
                lis[i+1]=0
        else:
            if lis[i-1]==1:
                lis[i+1]=0
            else:
                lis[i+1]=1
    else:
        if s[i]=="o":
            if lis[i-1]==1:
                lis[i+1]=0
            else:
                lis[i+1]=1
        else:
            if lis[i-1]==0:
                lis[i+1]=0
            else:
                lis[i+1]=1

for i in product([0,1],repeat=2):
    lis=[0 for i in range(n)]
    lis[0],lis[1]=i[0],i[1]
    for i in range(1,n-1):
        nex(i)
    #print(lis)
    x=lis[0]
    y=lis[1]
    nex(n-1)
    nex(0)
    if x==lis[0] and y==lis[1]:
        for i in range(n):
            if lis[i]==1:
                print("S",end="")
            else:
                print("W",end="")
        sys.exit()
print(-1)
                
    
    

            
        

    

        
        
        
            
        

                