# coding: utf-8
A, B, C, X, Y = map(int, input().split())
print(min((A*X)+(B*Y),2*C*max(X,Y),2*C*min(X,Y)+((A*(X-Y)) if X>Y else B*(Y-X))))
