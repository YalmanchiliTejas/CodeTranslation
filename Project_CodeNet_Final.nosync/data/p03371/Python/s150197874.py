a, b, c, x, y = map(int, input().split())

A = []

A.append(a * x + b * y)

if x > y:
    A.append(2 * c * y + (x - y) * a)
    A.append(2 * c * x)
else:
    A.append(2 * c * x + (y - x) * b)
    A.append(2 * c * y)

print(min(A))