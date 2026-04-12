A, B, C, X, Y = map(int, input().split(' '))

candidate = []

candidate.append(C * X * 2 if X >= Y else C * X * 2 + B * (Y - X))
candidate.append(C * Y * 2 if X <= Y else C * Y * 2 + A *(X - Y))
candidate.append(A * X + B * Y)

print(min(candidate))