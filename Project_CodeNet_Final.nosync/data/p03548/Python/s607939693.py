x, y, z = map(int, input().split())

chairs = x // (y + z)

if ((chairs * y)+(chairs * z)+z) > x:
  print(chairs - 1)
else:
  print(chairs)

