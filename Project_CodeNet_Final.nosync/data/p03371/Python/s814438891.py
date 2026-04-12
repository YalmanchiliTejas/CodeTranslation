a, b, c, x, y = map(int, input().split())

normal_price = a * x + b * y
min_price = float('inf')
minn = min(x, y)
maxx = max(x, y)

for mi in range(2, maxx * 2 + 1, 2):
    mix_price = c * mi
    xz = x - mi // 2
    yz = y - mi // 2
    if xz < 0: xz = 0
    if yz < 0: yz = 0
    x_price = xz * a
    y_price = yz * b
    total_price = mix_price + x_price + y_price
    min_price = min(min_price, total_price)

min_price = min(min_price, normal_price)
print(min_price)