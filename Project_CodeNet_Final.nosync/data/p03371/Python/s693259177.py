# coding: utf-8
from math import ceil

A,B,AB,x,y = list(map(int,input().split()))
p = []
for i in range(0,max(x,y)*2+1,2):
    ab = i
    a = max(0,ceil(x - (1/2)*i))
    b = max(0,ceil(y - (1/2)*i))
    p.append(A*a+B*b+AB*ab)
print(min(p))