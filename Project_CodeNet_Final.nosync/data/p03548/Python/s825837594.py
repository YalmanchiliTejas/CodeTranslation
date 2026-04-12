x,y,z = map(int,input().split())
aa = x
b1 = 0
b2 = 0
for a in range(aa):
  x -= z
  if x < y:
    break
  x -= y
  if x < z:
    break
  b2 += 1
if b1 <= b2:
  print(b2)
else:
  print(b1)