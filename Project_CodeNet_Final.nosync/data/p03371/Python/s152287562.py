a, b, c, x, y = map(int, input().split())
price = a * x + b * y
for i in range(min(x,y)):
    if a + b > 2 * c:
        price = price - (a + b) + 2 * c
    else:
        break

for i in range(max(x, y) - min(x, y)):
    if (x > y):
        if (a > 2 * c):
            price = price - a + 2 * c
        else:
            break
    else:
        if (b > 2 * c):
            price = price - b + 2 * c 
print(price)
