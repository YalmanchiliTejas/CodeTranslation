#ceilevenoddformula
import math
import bisect
import copy
import time
from collections import Counter
from itertools import combinations
#map(int,input().split())
#int(x) for x in input().split()
n=int(input())
l=[int(x) for x in input().split()]
ans=[0]*n
l=l[::-1]
ans[0]=l[0]
for i in range(1,n):
	ans[i]=l[i]+ans[i-1]
l=l[::-1]
c=0
M=10**9+7
ans=ans[::-1]
for i in range(1,n):
	c+=(ans[i]*l[i-1])%M
	c=c%M
print(c)







































