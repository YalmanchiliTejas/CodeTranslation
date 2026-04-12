a, b, c, x, y = map(int,input().split())

min_xy = min(x, y) 
max_xy = max(x, y)

min_xy_cost = min(a + b, c * 2) * min_xy

if x >= y:
  rest = x - y
  rest_cost = rest * min(a, c * 2)
else:
  rest = y - x
  rest_cost = rest * min(b, c * 2)
  
total = min_xy_cost + rest_cost

print(total)