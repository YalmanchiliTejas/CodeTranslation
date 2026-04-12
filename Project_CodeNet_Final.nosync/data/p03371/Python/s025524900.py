a, b, c, x, y = map(int,input().split())

price = a * x + b * y
for i in range(max(x,y)+1):
    new_price = c * 2 * i + max(a * (x - i),0) + max(b * (y - i),0)
    price = min(price,new_price)

print(price)