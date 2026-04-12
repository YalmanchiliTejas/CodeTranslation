# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

r,g,b =input().split()

co = int(r + g + b)
if co% 4 == 0:
    print('YES')
else:
    print('NO')
