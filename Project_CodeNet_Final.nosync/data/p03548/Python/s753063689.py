import math
X,Y,Z = map(int, input().split())

X1 = X - Z
Y1 = Y + Z

N = X1// Y1

print(N)