# -*- coding: utf-8 -*-
import sys
import os

x,y,z = [input() for i in range(3)]
x = int(x)
z = int(z)

moji = y[z-1]

y = list(y)

for i in range(x):
    if y[i] != moji:
        y[i] = '*'

print("".join(y))