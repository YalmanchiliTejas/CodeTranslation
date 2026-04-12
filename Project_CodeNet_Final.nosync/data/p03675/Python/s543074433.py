#!/usr/bin/env python3
n = int(input())
a = input().split()
l = []
r = []
for a_i in a:
    r += [ a_i ]
    l, r = r, l
print(*(list(reversed(l)) + r))
