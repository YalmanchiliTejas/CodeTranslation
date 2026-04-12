import math

A, B, C, X, Y = map(int, input().split())
m = 10000000000

for c in range(max(X, Y) * 2 + 1):
    a = math.ceil(X - 0.5 * c) if X - 0.5 * c >= 0 else 0
    b = math.ceil(Y - 0.5 * c) if Y - 0.5 * c >= 0 else 0
    m = min(a * A + b * B + c * C, m)

print(m)