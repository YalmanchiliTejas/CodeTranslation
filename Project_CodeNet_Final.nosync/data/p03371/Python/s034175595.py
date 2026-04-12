A, B, C, X, Y = map(int, input().split())
if X > Y:
    Z = C * Y * 2 + A * (X-Y)
else:
    Z = C * X * 2 + B * (Y-X)
print(min(A*X+B*Y, C*max(X,Y)*2, Z))