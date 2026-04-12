import bisect
from collections import deque
from collections import defaultdict
from fractions import gcd
#from math import factorial
from math import sqrt
from math import ceil
from itertools import permutations
from heapq import *

N=int(input())
A=[]
B=[]
for _ in range(N):
    a=int(input())
    A.append(a)
    B.append(a)
A.sort()
B.sort()
A=deque(A)
B=deque(B)
L=deque()
L.append(A.popleft())
num=0
while(A):
    if num==0:
        L.appendleft(A.pop())
        num+=1
    elif num==1:
        L.append(A.pop())
        num+=1
    elif num==2:
        L.appendleft(A.popleft())
        num+=1
    elif num==3:
        L.append(A.popleft())
        num=0
sum1=0
for i in range(N-1):
    sum1+=abs(L[i]-L[i+1])
R=deque()
R.append(B.pop())
num=2
while(B):
    if num==0:
        R.appendleft(B.pop())
        num+=1
    elif num==1:
        R.append(B.pop())
        num+=1
    elif num==2:
        R.appendleft(B.popleft())
        num+=1
    elif num==3:
        R.append(B.popleft())
        num=0
sum2=0
for i in range(N-1):
    sum2+=abs(R[i]-R[i+1])

print(max(sum1,sum2))
