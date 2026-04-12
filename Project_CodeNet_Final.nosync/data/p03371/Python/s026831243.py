A, B, C, X, Y = map(int, input().split())

answer = 0
if A + B < 2 * C:
  answer = (A + B) * min(X, Y)
else:
  answer = 2 * C * min(X, Y)

if A < 2 * C and Y < X:
  answer += A * (X - Y)
elif B < 2 * C and X < Y:
  answer += B * (Y - X)
else:
  answer += 2 * C * abs(X - Y)

print(answer)