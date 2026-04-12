a, b, c, x, y = map(int, input().split())

ans = float('inf')
for i in range(10 ** 5 + 1):
    price = i * 2 * c
    if x > i:
        price += a * (x - i)
    if y > i:
        price += b * (y - i)
    ans = min(ans, price)

print(ans)
