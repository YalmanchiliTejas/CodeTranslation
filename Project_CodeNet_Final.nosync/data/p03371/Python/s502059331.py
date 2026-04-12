A, B, C, X, Y = map(int, input().split())

m = A * X + B * Y
for i in range(1, 10 ** 5 + 1):
    m = min(m, i * 2 * C + A * max(0, X-i) + B * max(0, Y-i))

print(m)
