A,B,C,X,Y = map(int, input().split())
cost = 0
if X == Y:
    cost = X*min(A+B, 2*C)
if X < Y:
    cost = X*min(A+B, 2*C)
    R = Y-X
    cost += R*min(B, 2*C)
if Y < X:
    cost = Y*min(A+B, 2*C)
    R = X-Y
    cost += R*min(A, 2*C)
print(cost)