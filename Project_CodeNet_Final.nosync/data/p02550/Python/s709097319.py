import sys
#import numpy as np
import math
#from fractions import Fraction
import itertools
from collections import deque
from collections import Counter
import heapq
from fractions  import gcd
#input=sys.stdin.readline
#import bisect
n,x,m=map(int,input().split())
s=[x]
g=set()
cnt=0
l=-1
g.add(x)
b=x
for i in range(1,n):
    nt=pow(b,2,m)
    b=nt
    if nt not in g:
        s.append(nt)
        g.add(nt)
    else:
        cnt=i
        l=nt
        break
if l==0:
    #s=list(s)
    ans=sum(s)
elif l==1:
    #s=list(s)
    ans=n-cnt+sum(s)
else:
    if l!=-1:
      idx=s.index(l)
      c=len(s)-idx
      r=(n-cnt)%c
      ans=((n-cnt)//c)*sum(s[idx:])+sum(s[idx:idx+r])+sum(s)
    else:
      ans=sum(s)
print(ans)