x,y,z = map(int,input().split())
if x % (y + z) >= z:
  print(x // (y + z))
else:
  print(x // (y + z) - 1)