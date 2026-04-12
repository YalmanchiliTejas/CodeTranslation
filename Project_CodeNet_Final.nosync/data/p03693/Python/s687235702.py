# -*- coding: utf-8 -*-

r,g,b = map(int, input().split())

val = r*100+g*10+b
if val%4==0:
    print("YES")
else:
    print("NO")