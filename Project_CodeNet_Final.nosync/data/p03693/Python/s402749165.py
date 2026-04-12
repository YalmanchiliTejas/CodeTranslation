r, g, b = map(int, input().split())
s = 100*r + 10*g + b
if s%4 == 0:
  print("YES")
else:
  print("NO")