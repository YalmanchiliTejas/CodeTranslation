A, B, C, X, Y = map(int, input().split())
Sum = A * X + B * Y

if A+B > 2*C:
  if X < Y:
    if 2*C <= B:
      Sum = C * 2 * Y
    else:
      Sum = C * 2 * X + B * (Y - X)
  elif Y < X:
    if 2*C <= A:
      Sum = C * 2 * X
    else:
      Sum = C * 2 * Y + A * (X - Y)
  else:
    Sum = C * 2 * X

print(Sum)