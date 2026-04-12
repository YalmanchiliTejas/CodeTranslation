a, b, c, x, y = map(int, input().split())

d = abs(x - y)
price = 0
num = 0
if x > y:
    if a <= 2 * c:
        price += d * a
        num = y
    else:
        price += d * 2 * c
        num = y
else:
    if b <= 2 * c:
        price += d * b
        num = x
    else:
        price += d * 2 * c
        num = x



if (a+b) >= 2*c:
    price += 2 * c * num
else:
    price += (a+b) * num

print(price)