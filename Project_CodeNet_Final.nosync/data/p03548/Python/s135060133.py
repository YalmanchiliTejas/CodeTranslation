import math
x,y,z = map(int,input().split())
x = x-z
print(math.floor(x/(y+z)))
