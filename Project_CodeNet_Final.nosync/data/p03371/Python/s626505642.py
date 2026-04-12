# encoding: utf-8
A, B, C, X, Y = map(int, input().split())

candidate = [0] * 3

# all A or B
candidate[0] = A * X + B * Y

# either is replaced into AB
if X < Y: candidate[1] = (2 * C) * X + B * (Y - X)
else: candidate[1] = (2 * C) * Y + A * (X - Y)

# both is replaced into AB
candidate[2] = (2 * C) * max((X, Y))

print(min(candidate))