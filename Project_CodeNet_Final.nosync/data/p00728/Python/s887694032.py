#import pysnooper
#import os,re,sys,operator,math,heapq,string
#from collections import Counter,deque
#from operator import itemgetter
#from itertools import accumulate,combinations,groupby,combinations_with_replacement
from sys import stdin,setrecursionlimit
#from copy import deepcopy

setrecursionlimit(10**6)
input=stdin.readline

while 1:
    n=int(input().rstrip())
    if n==0:
        break
    print(sum(sorted([int(input().rstrip()) for _ in range(n)])[1:-1])//(n-2))
