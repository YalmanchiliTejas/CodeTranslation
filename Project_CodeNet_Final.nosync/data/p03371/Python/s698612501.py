A, B, C, X, Y = map(int, input().split())
money = 0
if A + B > C * 2:
    money += (C * 2) * min(X, Y)
    if X == Y:
        pass
    elif X > Y:
        money += (X - Y) * min(A, C * 2)
    elif X < Y:
        money += (Y - X) * min(B, C * 2)
else:
    money += A * X + B * Y

print(money)
