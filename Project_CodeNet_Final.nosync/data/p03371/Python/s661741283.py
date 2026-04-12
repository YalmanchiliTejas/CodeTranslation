A, B, C, X, Y = map(int, input().split())
cost = [(A * X + B * Y), (C * 2 * max(X, Y))]
if X >= Y:
    cost.append(C * (2 * Y) + A * (X - Y))
if X <= Y:
    cost.append(C * (2 * X) + B * (Y - X))
print(min(cost))