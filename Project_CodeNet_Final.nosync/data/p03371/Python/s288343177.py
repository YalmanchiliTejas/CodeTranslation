a, b, c, x, y = [int(i) for i in input().split()]

if (a + b) <= c * 2:
  cost_over = 10 ** 100
  cost = a * x + b * y 
else: 
  if x <= y:
    cost_over = c * 2 * y
    cost = c * 2 * x + b * (y - x)
  else: 
    cost_over = c * 2 * x
    cost = c * 2 * y + a * (x - y)

min = min(cost, cost_over)
print(min)

  