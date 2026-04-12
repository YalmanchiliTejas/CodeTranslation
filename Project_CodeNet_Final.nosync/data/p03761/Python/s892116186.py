#!/usr/bin/env python
# coding:utf-8
import os, sys
import math
from collections import defaultdict
n=input()
S=[]
c = defaultdict(lambda:1000000)
chars = set()
for _ in range(n):
    s=raw_input()
    chars |= set(s)

    co = defaultdict(int)
    for w in s:
        co[w]+=1
    S.append(co)

M = defaultdict(lambda:1000)
for c in chars:
    for s in S:
        M[c] = min(M[c], s[c])

w = ""
for k,v in M.iteritems():
    w += k*v
print "".join(sorted(w))





