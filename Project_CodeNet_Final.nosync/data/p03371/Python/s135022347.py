a, b, c, x, y = map(int, input().split())
c2 = c * 2
print(min([i * c2 + max(0, x - i) * a + max(0, y - i) * b for i in range(10**6)]))