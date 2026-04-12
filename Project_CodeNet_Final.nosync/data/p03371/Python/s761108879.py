a, b, c, x, y = map(int, input().split())

cost = a*x+b*y

for i in range(max(x,y)):
  if min(x, y)-i-1 >=0:
    if cost > a*(x-i-1)+b*(y-i-1)+c*(i+1)*2:
      cost = a*(x-i-1)+b*(y-i-1)+c*(i+1)*2
  elif x-i-1 < 0:
    if cost > b*(y-i-1)+c*(i+1)*2:
      cost = b*(y-i-1)+c*(i+1)*2
  else:
    if cost > a*(x-i-1)+c*(i+1)*2:
      cost = a*(x-i-1)+c*(i+1)*2

print(cost)
    