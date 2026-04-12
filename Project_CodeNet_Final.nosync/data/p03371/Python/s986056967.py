A, B, C, X, Y = map(int, input().split())
C *= 2
if X == Y:
    print(min(C * X, A * X + B * Y))
if X > Y:
    print(min(C * X, C * Y + A * (X - Y), A * X + B * Y))
if X < Y:
    print(min(C * Y, C * X + B * (Y - X), A * X + B * Y))
