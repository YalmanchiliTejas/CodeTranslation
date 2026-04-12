f = lambda :[int(i) for i in input().split()]
from sys import stderr
from functools import reduce
from operator import add
debug = lambda *x:stderr.write(reduce(add,repr(x))+'\n')

n = int(input())
x = f()
y = sorted(x)
med = (y[int(n/2)]+y[int(n/2)-1])/2
lmed = y[int(n/2)]
smed = y[int(n/2)-1]

for po in x:
    if po < med:
        print(lmed)
    else:
        print(smed)
        