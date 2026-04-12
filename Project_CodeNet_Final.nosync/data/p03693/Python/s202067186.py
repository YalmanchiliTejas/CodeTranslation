r, g, b = map(int,input().split())

n = (10*g + b) % 4

if n == 0:
  print("YES")
else:
  print("NO")
