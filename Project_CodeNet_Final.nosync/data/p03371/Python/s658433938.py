A, B, C, X, Y = map(int, input().split())
 
p1 = 2 * C * min(X, Y) + A * (X - min(X, Y)) + B * (Y - min(X, Y))
p2 = 2 * C * max(X, Y)
p3 = A * X + B * Y
print(min(p1, p2, p3))