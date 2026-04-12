a, b, c, x, y = map(int, input().split())
mini = 10000000000
if x < y: temp = y
else: temp = x
for i in range(0, temp * 2 + 1, 2):
    a_price = a * (x - int(i/2))
    b_price = b * (y - int(i/2))
    if a_price < 0:
        a_price = 0
    if b_price < 0:
        b_price = 0
    price = a_price + b_price + c * i
    # print(x - i/2, y - i/2, i, price)
    if price < mini:
        mini = price
print(mini)