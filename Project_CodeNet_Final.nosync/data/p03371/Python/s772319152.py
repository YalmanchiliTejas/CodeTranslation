#!/usr/bin/env python3
#input
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
a,b,c,x,y = map(int,input().split())
if 2*c <= a and 2*c <= b:
    print(max(x,y)*2*c)
elif 2*c <= a:
    print(x*2*c + max(0,y-x)*b)
elif 2*c <= b:
    print(y*2*c + max(0,x-y)*a)
elif 2*c <= a+b:
    if y < x:
        print(y*2*c + (x-y)*a)
    else: print(x*2*c + (y-x)*b)
else:
    print(a*x + b*y)