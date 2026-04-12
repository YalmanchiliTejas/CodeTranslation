A, B, C, X, Y = map(int, input().split())
print(min(A * X + B * Y, C * 2 * max(X,Y), C * 2 * min(X,Y) + max(A * (X - Y), B * (Y - X))))