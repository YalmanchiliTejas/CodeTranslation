# coding: utf-8
A,B,C,X,Y = map(int, input().split())
minprice = 10**10
for i in range(max(X,Y)+1):
    tmp = 0
    tmp += C * i*2
    tmp += A * max(0,X-i)
    tmp += B * max(0,Y-i)
    minprice = min(minprice, tmp)
print(minprice)