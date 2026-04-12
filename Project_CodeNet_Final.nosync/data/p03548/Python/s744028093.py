# coding: utf-8
# Your code here!

import copy
import math
A,B,C = input().split(" ")
A = int(A)
B = int(B)
C = int(C)

A = A - C
print(math.floor(A/(B+C)))