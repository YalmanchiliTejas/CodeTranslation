#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math

r,g,b = map(int, sys.stdin.readline().rstrip().split())

if( (r*100+g*10+b) % 4 == 0):
    print("YES")
else:
    print("NO")


exit(0)
