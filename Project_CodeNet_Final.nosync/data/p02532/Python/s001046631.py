#!/usr/bin/env python
# -*- coding:utf-8 -*-
import time
import sys
import io
import re
import math
start = time.clock()
a=int(raw_input())
l=[[] for x in xrange(a+1)]
#print l
while 1:
    n = raw_input().split()
    if str(n[0]) == 'quit': break
    elif n[0]=='pop':
        print l[int(n[1])][-1]
        del l[int(n[1])][-1]
    elif n[0]=='move':
        l[int(n[2])].append(l[int(n[1])][-1])
        del l[int(n[1])][-1]
    else:
        l[int(n[1])].append(n[2])