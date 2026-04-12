import os, sys, re, math

(H, W) = [int(i) for i in input().split()]
a = []
for i in range(H):
    r = input()
    if '#' in r:
        a.append(r)

a = [''.join(r) for r in zip(*a)]
a = filter(lambda r: '#' in r, a)
a = [''.join(r) for r in zip(*a)]

for r in list(a):
    print (r)
