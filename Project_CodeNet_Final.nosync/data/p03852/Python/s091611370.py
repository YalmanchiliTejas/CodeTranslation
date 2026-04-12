#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf')
ans = 0 ;count = 0 ;pro = 1

c=input()
data={x for x in "a i u e o".split()}
if c in data:
    print("vowel")
else:
    print("consonant")
