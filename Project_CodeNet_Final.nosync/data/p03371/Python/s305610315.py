import math

line = input().split()
a = int(line[0])
b = int(line[1])
c = int(line[2])
x = int(line[3])
y = int(line[4])

m = max(x, y)
price = a * x + b * y

for i in range(1 ,m + 1):
  tx = max(x - i, 0)
  ty = max(y - i, 0)  
  tprice = i * 2 * c + a * tx + b * ty
  if tprice < price:
    price = tprice

print(price)
