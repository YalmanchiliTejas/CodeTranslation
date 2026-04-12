a, b, c, x, y = map(int, input().split())

z = min(x, y)
total = z * min(a + b, c * 2)
total += (x - z) * min(a, c * 2)
total += (y - z) * min(b, c * 2)

print(total)