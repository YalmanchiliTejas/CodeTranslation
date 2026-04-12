a, b, c, x, y = map(int, input().split())

A = a * x + b * y
if x <= y: B = c * x * 2 + b * (y-x)
else: B = c * y * 2 + a * (x-y)
C = c * max(x, y) * 2

print(min(A, B, C))