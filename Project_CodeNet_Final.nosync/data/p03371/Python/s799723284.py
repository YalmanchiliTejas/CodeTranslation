a, b, c, x, y = map(int, input().split())

z = min(x, y)
total = z * min(a + b, 2 * c)
total += (x - z) * min(a, 2 * c)
total += (y - z) * min(b, 2 * c)

print(total)