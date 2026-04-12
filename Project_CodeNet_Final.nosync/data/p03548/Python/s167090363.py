# -*- coding: utf-8 -*-

xyz = list(map(int, input().split()))
x = xyz[0]
y = xyz[1]
z = xyz[2]

width = z + y + z

num = 0

while(width <= x):
    width = width + y + z
    num = num + 1

print(num)