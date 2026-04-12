x,y,z = map(int,input().split())
s = z
count = 0

for i in range(10**99):
  s += y
  if s <= x-z:
    count += 1
  elif s> x-z:
    break
  s+= z
  
print(count)