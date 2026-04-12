A, B, C, X, Y = map(int, input().split())

values = []

values.append(A*X + B*Y)

if X >= Y:
    values.append(2*C*X)
    values.append(2*C*Y + A*(X-Y))
else:
    values.append(2*C*Y)
    values.append(2*C*X + B*(Y-X))

print(min(values))
