# -*- coding: utf-8 -*-
a,b,c,x,y = [int(i) for i in input().split()]

if x <= y:
    ans1 = min(c * x * 2 + b * (y - x), c * y * 2)
    #print('a')
else: #x > y
    ans1 = min(c * y * 2 + a * (x - y), c * x * 2)
    #print('b')
ans2 = a * x + b * y
print(min(ans1, ans2))
