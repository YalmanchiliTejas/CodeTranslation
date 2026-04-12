x, y, z = map(int, input().split())
x -= z
if x >= 0:
   print(x//(y+z))
else:
    print(0)
