a, b, c, x, y = list(map(int, input().split()))

p = 0

z1 = a * x + b * y
z2 = 2 * c * min(x, y) + a * max(x-y, 0) + b * max(y-x, 0)
z3 = 2 * c * max(x, y)

print(min(z1, z2, z3))