a, b, c, x, y = map(int, input().split())

ab = 2 * c
money = 0

if a + b >= ab:
    if x >= y:
        if  a >= ab:
            money = x * ab
        else:
            money = (x - y) * a + y * ab
    else:
        if b >= ab:
            money = y * ab 
        else:
            money = (y - x) * b + x * ab

else:

    if a < ab and b < ab:
        money = a*x + b*y

    if a >= ab and b < ab:
        if y - x >= 0:
            money = x * ab + b * (y - x)
        else:
            money = x * ab

    if a < ab and b >= ab:
        if x -y >= 0:
            money = y * ab + a * (x -y)
        else:
            money = y * ab

    if a >= ab and b >= ab:
        money = x * ab + y * ab

print(money)