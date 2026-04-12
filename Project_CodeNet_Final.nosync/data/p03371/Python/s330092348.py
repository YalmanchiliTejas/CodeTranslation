a, b, c, x, y = map(int, input().split())

min_price = 2 * 5000 * 100000
for nab in range(0, 2 * max(x, y) + 1, 2):
    na = max(0, x - nab // 2)
    nb = max(0, y - nab // 2)
    min_price = min(min_price, nab * c + na * a + nb * b)

print(min_price)