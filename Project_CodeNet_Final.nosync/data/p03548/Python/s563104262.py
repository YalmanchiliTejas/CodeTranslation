x, y, z = map(int, input().split())

rem = x % (y+z)
if rem >= z:
  print(x // (y+z))
else:
  print(x // (y+z) - 1)  