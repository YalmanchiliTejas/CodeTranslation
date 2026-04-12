import math

(a, b, c, x, y) = map(int, input().split())

a1 = max(x, y) * c * 2

a2 = min(x, y) * c * 2 + a * (x - min(x, y))+ b * (y - min(x, y))

a3 = a * x + b * y

answer = min(a1, a2, a3)
print(str(answer))