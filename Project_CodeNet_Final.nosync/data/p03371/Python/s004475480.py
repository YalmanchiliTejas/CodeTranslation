# -*- coding: utf-8 -*-
A,B,C,X,Y = map(int, input().split())

prices = []
for c in range(0,max([X,Y])*2+1,2):
    a = max([X - c//2, 0])
    b = max([Y - c//2, 0])
    prices.append(A*a+B*b+C*c)

print(min(prices))
