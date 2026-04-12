a, b, c, x, y = map(int, input().split())
val = float('inf')
for k in range(10 ** 5 + 1):
    val = min(val, 2 * c * k + max(x - k, 0) * a + max(y - k, 0) * b)
print(val)