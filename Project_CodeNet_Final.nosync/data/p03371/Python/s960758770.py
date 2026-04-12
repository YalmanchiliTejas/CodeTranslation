a, b, c, x, y = map(int, input().split())
prc = 10**10
for i in range(max(x, y) * 2 + 1):
    prc = min(max(x - i // 2, 0) * a + max(y - i // 2, 0) * b + i * c, prc)
print(prc)