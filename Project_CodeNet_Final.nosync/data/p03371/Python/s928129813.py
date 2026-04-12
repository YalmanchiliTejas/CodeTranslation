a, b, c, x, y = map(int, input().split())
min_cost = 10**10

#fit x
price = 0
num_c = x * 2
price += c * num_c
if x < y:
  price += (y - x) * b
min_cost = min(min_cost, price)

#fit y
price = 0
num_c = y * 2
price += c * num_c
if x > y:
  price += (x - y) * a
min_cost = min(min_cost, price)

#buy each
min_cost = min(min_cost, a * x + b * y)

print(min_cost)