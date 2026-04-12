from numpy import median
from copy import deepcopy

n = int(input())
x = list(map(int,input().split()))

sx = sorted(x)
newl = deepcopy(sx)
del newl[0]
maxm = median(newl)
newl = deepcopy(sx)
del newl[-1]
minm = median(newl)

med = median(x)

for i in x:
    if i > med:
        print(int(minm))
    else:
        print(int(maxm))
