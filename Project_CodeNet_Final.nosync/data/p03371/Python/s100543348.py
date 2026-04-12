A, B, C, X, Y = tuple(map(int, input().split()))

byeEachAB = A * X + B * Y
byeABless = A * (X - min(X, Y)) + B * (Y - min(X, Y)) + C * min(X, Y) * 2
byeABmore = C * max(X, Y) * 2
print(min(byeEachAB, byeABless, byeABmore))