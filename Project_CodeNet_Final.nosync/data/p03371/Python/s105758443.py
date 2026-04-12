a, b, c, x, y = map(int, input().split())
A = x * a + y * b
if x >= y:
    B = y * 2 * c + (x - y) * a
else:
    B = x * 2 * c + (y - x) * b

C = max(x, y) * 2 * c
print(min(A, B, C))
