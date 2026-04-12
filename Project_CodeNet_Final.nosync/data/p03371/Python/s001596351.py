A, B, C, X, Y = map(int, input().split())

minp = A * X + B * Y
for i in range (1, 100001):
    p = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i)
    if p < minp:
        minp = p
print(minp)