A, B, C, X, Y = map(int, input().split())

ret = A * X + B * Y
X -= 1
Y -= 1
Z = 2
while X >= 0 or Y >= 0:
    ret = min(ret, max(0, A * X) + max(0, B * Y) + C * Z)
    X -= 1
    Y -= 1
    Z += 2

print(ret)
