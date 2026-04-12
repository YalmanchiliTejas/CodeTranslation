import sys,os
import math
from fractions import Fraction 
from collections import defaultdict
from random import randint

# sys.stderr=open('err.txt','w')
# sys.stdout=open('output.txt','w')
# sys.stdin=open('input.txt','r')

def linput():
    return list(minput())

def minput():
    return map(int, sys.stdin.readline().strip().split())

###############################################################

n=int(input())
a=linput()

ans,s=0,0
mod=10**9+7
for i in a:
    s=(s+i)%mod
now=0
for i in a:
    now+=i
    cur=(s-now)%mod
    ans=(ans+(i*(cur))%mod)%mod
print(ans)
