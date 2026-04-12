#!/usr/bin/env python

r,g,b=map(int,raw_input().split())

if (100*r+10*g+b)%4:
    print 'NO'
else:
    print 'YES'