import time
import random
def calc(a) :
    sum = 0
    for i in range(len(a) - 1):
        sum += abs(a[i + 1] - a[i])
    return sum

def crossList(a,b):
    y = []
    if len(a) > len(b):
        for i in range(len(b)):
            y.append(a[i])
            y.append(b[i])
        y.append(a[i+1])
    elif len(a) < len(b): 
        for i in range(len(a)):
            y.append(b[i])
            y.append(a[i])
        y.append(b[i+1])
    else :
        for i in range(len(a)):
            y.append(b[i])
            y.append(a[i])
    return y

n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()
b = []
c = []
if len(a) % 2 == 1:
    b = a[0:int((len(a) - 1)/2) ]
    c = a[int((len(a) - 1)/2) : len(a)]
else :
    b = a[0:int((len(a) )/2)  ]
    c = a[int((len(a) )/2) : len(a)]
c.reverse()
d = []
e = []
forward = True;
for i in range(len(b)):
    if forward:
        d.append(b[i])
    else :
        d.insert(0,b[i])
    forward = not forward
forward = True

for i in range(len(c)):
    if forward:
        e.append(c[i])
    else :
        e.insert(0,c[i])
    forward = not forward

h = d[:]
j = e[:]
if len(a) % 2 == 1:
    if (len(h) % 2 == 0) :
        h.append(j.pop(-1))
    else:
        h.insert(0,j.pop(0))

print(max(calc(crossList(d,e)),calc(crossList(d[::-1],e[::-1])),
          calc(crossList(d,e[::-1])),calc(crossList(d[::-1],e)),
          calc(crossList(h[::-1],j[::-1])),calc(crossList(h,j[::-1])),
          calc(crossList(h[::-1],j)),calc(crossList(h,j))))

