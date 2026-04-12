a, b, c, x, y = map(int, input().split())

Price = []

for k in range(min(x, y)+1):
  Price.append((2*c-a-b)*k + a*x + b*y)
Price.append(max(x,y)*2*c)

print(min(Price))