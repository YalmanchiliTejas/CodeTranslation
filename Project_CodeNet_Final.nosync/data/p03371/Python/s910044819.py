from sys import stdin,stdout
def INPUT():return list(int(i) for i in stdin.readline().split())
def inp():return stdin.readline()
def out(x):return stdout.write(x)
import math
import random
J=998244353
from collections import deque
########################################################
a,b,c,x,y=INPUT()
#cost of 1 pi is a+b or 2*c
if 2*c<(a+b):
    cost=2*c*min(x,y)
    if x>y:
        r=x-y
        if 2*c>a:
            cost+=r*a
        else:
            cost+=r*(2*c)
        print(cost)
    else:
        r=y-x
        if 2*c>b:
            cost+=r*b
        else:
            cost+=r*(2*c)
        print(cost)
else:
    print(x*a+y*b)
