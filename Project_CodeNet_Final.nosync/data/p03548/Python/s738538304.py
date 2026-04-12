X, Y, Z = map(int, input().split())

width = X - 2 * Z
if width < Y:
  print(0)
  exit()
  
num = (width - Y) // ( Y + Z)
print(num + 1)