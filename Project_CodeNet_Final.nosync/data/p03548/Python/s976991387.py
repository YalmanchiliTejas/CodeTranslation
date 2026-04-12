x, y, z = map(int, input().split())
m = y+z
c = 0
if x%m < z:
  c = 1
  
print(x//m - c)