A, B, C, X, Y = map(int, input().split())

ab = min(C * 2, A + B) #A, B1枚ずつ用意するのにかかるお金の最小値
a = min(C * 2, A)
b = min(C * 2, B)
if X >= Y:
    print(ab * Y + a * (X - Y))
else:
    print(ab * X + b * (Y - X))