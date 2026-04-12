A, B, C, X, Y = map(int, input().split())
sum_1 = A * X + B * Y
sum_2 = C * min(X, Y) * 2 + A * (X - min(X, Y)) + B * (Y - min(X, Y))
sum_3 = C * max(X, Y) * 2
print(min(sum_1, sum_2, sum_3))