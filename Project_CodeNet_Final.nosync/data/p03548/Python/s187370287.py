import math

x,y,z=map(int,input().split())

if x%(y+z)>=z:
  print(math.floor(x/(y+z)))
else:
  print(math.floor(x/(y+z)-1))