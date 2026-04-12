# coding: UTF-8
import math
a,b,c,d,e = map(int, input().split())
flag = 0
flaga = 0
flagb = 0
cost = 0
if(a+b< 2*c):
    cost = a*d + b*e
    flag = 1
if(2*c<=a):
    flaga = 1#aが余ったらc2枚買えばいい
if(2*c<=b):
    flagb = 1#bが余ったらc2枚買えばいい

if(flag == 0):#同じ枚数分はcを買う
    if(d<=e):#bを追加で買わな
        if(flagb == 1):
            cost += e * 2 * c
        else:
            cost += d * 2 * c + (e-d)*b
    else:
        if(flaga == 1):
            cost += d * 2 * c
        else:
            cost += e * 2 * c + (d-e)*a
print(cost)
