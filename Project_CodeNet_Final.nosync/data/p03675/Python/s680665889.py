#!usr/bim/python
#! -*- coding: utf-8 -*-

import numpy as np

n = raw_input()
n = int(n)
a = raw_input()
a = a.split()

m = n/2
b = []

if n % 2 == 0:
    i = 0
    while i < m:
        b.append(a[2*(m-i)-1])
        i += 1
    i = 0
    while i < m:
        b.append(a[2*i])
        i += 1

else:
    i = 0
    while i <= m:
        b.append(a[2*(m-i)])
        i += 1
    i = 0
    while i < m:
        b.append(a[2*i+1])
        i += 1

for s in b:
    print s+" ",
print ""
