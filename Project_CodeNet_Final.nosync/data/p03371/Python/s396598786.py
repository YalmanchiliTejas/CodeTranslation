A, B, C, X, Y = map(int, input().split())

miab = min(X, Y)
c1 = A * X + B * Y
c2 = C * miab * 2 + A * (X - miab) + B * (Y - miab)
c3 = C * max(X, Y) * 2

print(min(c1, c2, c3))