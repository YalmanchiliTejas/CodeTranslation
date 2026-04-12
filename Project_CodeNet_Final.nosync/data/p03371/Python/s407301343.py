# -*- coding: utf-8 -*-

A,B,C,X,Y = map(int, input().split())

m = []

#Cを買わない
m.append(A*X + B*Y)

#Aを買い足す
if X > Y:
    m.append( (X-Y)*A + 2*Y*C )
#Bを買い足す
if X < Y:
    m.append( (Y-X)*B + 2*X*C )
#Cだけ買う
if X < Y:
    m.append(2*Y*C)
elif X == Y:
    m.append(2*Y*C)
else:
    m.append(2*X*C)

print(min(m))