# -*- coding: utf-8 -*-


a,b,c,x,y = map(int,input().split())

minprice = float("inf")

for i in range(1000001):
    buya = max(0,x - int(i / 2))
    buyb = max(0,y - int(i / 2))
    buyc = i
    price = buya * a + buyb * b + buyc * c
    if price < minprice:
        minprice = price

print(minprice)
