A, B, C, X, Y = map(int, input().split())
C *= 2
if X == Y:
    print(min(X * C, X * (A + B)))
if X > Y:
    print(min(C * Y, A * Y + B * Y) + min(C, A) * (X - Y))
if Y > X:
    print(min(C * X, A * X + B * X) + min(C, B) * (Y - X))
