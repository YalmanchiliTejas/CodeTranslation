a, b, c, x, y = map(int, input().split())
if (a+b) <= 2*c:
    print(x*a+y*b)
else:
    price = min(x, y) * 2 * c
    n = abs(x - y)
    if x - min(x, y) > 0:
        if a*n <  2*c*n:
            price += a*n
        else:
            price += 2*c*n
    if y - min(x, y) > 0:
        if b*n <  2*c*n:
            price += b*n
        else:
            price += 2*c*n
    print(price)
