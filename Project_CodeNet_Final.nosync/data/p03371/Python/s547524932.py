A, B, C, X, Y = map(int, input().split())

if A + B < 2*C:
    print(A*X + B*Y)
else:
    Z =min(X,Y)
    print(min(2*C*max(X,Y), 2*C*Z+A*(X-Z)+B*(Y-Z)))