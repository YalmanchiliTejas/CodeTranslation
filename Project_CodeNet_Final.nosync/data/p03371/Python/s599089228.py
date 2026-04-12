a, b, c, x, y = [int(item) for item in input().split()]
c *= 2

gA_B = x * a + y * b
gAB = max(x,y) * c
if y > x:
  gAB_B = x * c + (y-x) * b
else:
  gAB_B = gAB
if x > y:
  gA_AB = (x-y) * a + y * c
else:
  gA_AB = gAB
  
print(min(gA_B, gAB, gA_AB, gAB_B))
  