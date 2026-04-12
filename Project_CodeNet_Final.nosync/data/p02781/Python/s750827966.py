#import sys
#import numpy as np
#import sys
#import numpy as np
import math
#from fractions import Fraction
import itertools
from collections import deque
from collections import Counter
#import heapq
#from fractions  import gcd
#input=sys.stdin.readline
import bisect
n=input()
k=int(input())
if k==1:
    a=int(n[0])
    l=len(n)
    ans=9*(l-1)+a
elif k==2:
    a=int(n[0])
    A=len(n)
    for i in range(1,A):
        if n[i]!="0":
            b=int(n[i])
            B=A-i
            break
    else:
        B=1
        b=0
    ans=9*(a-1)*(A-1)+(B-1)*9+b
    for i in range(2,A):
        ans+=81*(i-1)
else:
    a=int(n[0])
    A=len(n)
    for i in range(1,A):
        if n[i]!="0":
            b=int(n[i])
            B=A-i
            for j in range(i+1,A):
                if n[j]!="0":
                    c=int(n[j])
                    C=A-j
                    break
            else:
                c=0
                C=1
            break
    else:
        c=b=0
        C=B=1
    ans=(a-1)*81*(A-1)*(A-2)//2+81*(B-1)*(B-2)//2+(b-1)*9*(B-1)+9*(C-1)+c
    for i in range(3,A):
        ans+=729*(i-1)*(i-2)//2
print(ans)