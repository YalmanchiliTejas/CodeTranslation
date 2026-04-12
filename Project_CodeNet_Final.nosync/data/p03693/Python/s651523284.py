#! -*- coding:utf-8 -*-

r,g,b = map(int,input().split())
x = 100*r + 10*g + b

if x % 4 == 0:
    print('YES')
else:
    print('NO')
