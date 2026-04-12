a, b, c, x, y = map(int,input().split())
total = []

for i in range(0, max(x, y) + 1):
    c_price = i * 2 * c
    if x - i <= 0:
        a_price = 0
    else:
        a_price = (x - i) * a
    if y - i <= 0:
        b_price = 0
    else:
        b_price = (y - i) * b
    total.append(a_price + b_price + c_price)
print(min(total))
