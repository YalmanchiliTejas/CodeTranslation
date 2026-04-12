A, B, C, X, Y = map(int, input().split())
sum1 = A * X + B * Y
sum2 = C * min(X, Y) * 2 + A * (X - min(X, Y)) + B * (Y - min(X , Y))
sum3 = C * max(X, Y) * 2
print(min(sum1, sum2, sum3))