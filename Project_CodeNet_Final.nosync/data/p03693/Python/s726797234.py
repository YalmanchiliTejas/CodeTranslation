# -*- coding: utf-8 -*-
r, g, b = [int(n) for n in input().split()]
num = 100*r + 10*g +b
if num%4==0:
    print("YES")
else:
    print("NO")