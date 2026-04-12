# -*- coding: utf-8 -*-
# 
import math
import sys
import bisect

# いっこ入力
n =int(input())

# n行の数をリストへ
a = [int(input()) for i in range(n)] 

# color
c = [-999]*n

for i in range(0,n):
#    if c[0] >= a[i]:
#        c.insert(0,a[i])
#    else:
    p = bisect.bisect_left(c, a[i])
    c[p-1]=a[i]
#        print(c)
#        print(p)

print(len(c) - bisect.bisect_left(c, -1))
