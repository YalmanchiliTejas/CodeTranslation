A, B, C, X, Y = map(int, input().split(" "))
p1 = A * X + B * Y
p2 = C * min(X, Y) * 2
if X > Y:
    p2 += (X - Y) * A
else:
    p2 += (Y - X) * B
p3 = C * max(X, Y) * 2
print(min(p1, p2, p3))