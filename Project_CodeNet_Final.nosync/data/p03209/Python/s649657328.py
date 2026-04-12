# -*- coding: utf-8 -*-
n,x = map(int, input().split())

d = [0 for _ in range(51)]
d[0] = 1
for i in range(50):
    d[i+1] = 3 + 2*d[i]

p = [0 for _ in range(51)]
p[0] = 1
for i in range(50):
    p[i+1] = 1 + 2*p[i]

def f(l,x):
    if l==1:
        if x>3:
            return 3
        elif x<2:
            return 0
        else:
            return x-1
    if x==0:
        return 0
    if d[l]==x:
        return p[l]

    if 2+d[l-1]<=x:
        return f(l-1,d[l-1]) + 1 + f(l-1, x-1-d[l-1]-1)
    else:
        return f(l-1, x-1)

print(f(n,x))
