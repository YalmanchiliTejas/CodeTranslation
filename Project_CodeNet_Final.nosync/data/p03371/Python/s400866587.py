A, B, C, X, Y = map(int, input().split())
result = []
if X >= Y:
    result.append(X * C * 2)
    result.append(Y * C * 2 + (X-Y)*A)
else:
    result.append(Y * C * 2)
    result.append(X * C * 2 + (Y-X)*B)
result.append(X*A+Y*B)
print(min(result))
