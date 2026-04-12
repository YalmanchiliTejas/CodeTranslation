# -*- coding: utf-8 -*-

r, g, b = map(int,input().split())

a = 10*g + b

answer = a % 4

if answer == 0:
    print("YES")
else:
    print("NO")