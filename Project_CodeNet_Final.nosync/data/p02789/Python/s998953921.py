# -*- coding: utf-8 -*-
import sys
import math
import collections
#sys.setrecursionlimit(100000)

#n=int(input())
tmp = input().split()
a,b = list(map(lambda a: int(a), tmp))

if(a==b):
	print("Yes")
else:
	print("No")
