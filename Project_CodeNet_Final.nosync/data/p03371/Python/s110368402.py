A, B, C, X, Y = [int(i) for i in input().split()]
ma = max(X, Y)
mi = min(X, Y)
memo = []
if A + B > 2 * C:
    result1 = A * (X - mi) + B * (Y - mi) + C * 2 * mi
    result2 = C * 2 * ma
    print(min(result1, result2))
else:
    print(A * X + B * Y)
