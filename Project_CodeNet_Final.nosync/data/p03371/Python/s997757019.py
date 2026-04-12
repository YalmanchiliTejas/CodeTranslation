# coding: utf-8

A, B, C, X, Y = map(int, input().split())

ans = 0

pt1 =(A*X)+(B*Y)
pt2 = 2*C*max(X,Y)
pt3 = 2*C*min(X,Y)+((A*(X-Y)) if X>Y else B*(Y-X))

print(min(pt1,pt2,pt3))
