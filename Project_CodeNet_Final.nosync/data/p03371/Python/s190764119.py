a, b, c, x, y=[int(i) for i in input().split()]

price = 0

if x - y > 0:
    diff = x - y
    n_same = y
    rest_pr = a
else:
    diff = y - x
    n_same = x
    rest_pr = b


if a + b < c * 2:
    price += (a+b) * n_same
else:
    price += c * n_same * 2

if rest_pr < c * 2:
    price += rest_pr * diff
else:
    price += c * diff * 2

print(price)