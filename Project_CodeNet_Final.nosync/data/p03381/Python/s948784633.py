import numpy as np
n=int(input())
x=list(map(int,input().split(' ')))
x1=x[:]
x.sort()
m1=x[int(n/2)-1]
m2=x[int(n/2)]
for i in range(n):
    now=x1[i]
    if x1[i]<=m1:
        print(m2)
    else:
        print(m1)
