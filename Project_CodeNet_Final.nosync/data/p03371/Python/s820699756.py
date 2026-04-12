A, B, C, X, Y = map(int, input().split())
sum1 = A * X + B * Y
sum2 = A * (X - min(X, Y)) + B * (Y - min(X, Y)) + C * 2 * min(X, Y)
sum3 = C * 2 * max(X, Y)
print(min(sum1, sum2, sum3))