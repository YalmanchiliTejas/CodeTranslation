#!/usr/bin/env python
# -*- coding: utf-8 -*-
a,b,c,x,y = [int(i) for i in input().split()]

min_price = a * x + b * y

for i in range(100001):
    sum_price = a * max(0, x - i) + b * max(0, y - i) + c * 2 * i
    if sum_price <= min_price:
        min_price = sum_price

print(min_price)
