from sys import stdin
import numpy as np
a,b,c,x,y= [int(x) for x in stdin.readline().rstrip().split()]

if x >= y:
    print(min(a*x+b*y,c*2*y+a*(x-y),c*2*x))
else:
    print(min(a*x+b*y,c*2*x+b*(y-x),c*2*y))