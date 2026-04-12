a,b,c,x,y = map(int, input().split())

cost = 0

while x>0 or y>0:
  
  if a+b>=2*c:
    while x>0 and y>0:
      cost += 2*c
      x -= 1
      y -= 1
      
  if x>0:
    if a>=2*c:
      cost += 2*c
    else:
      cost += a
    x -= 1
  elif y>0:
    if b>=2*c:
      cost += 2*c
    else:
      cost += b
    y -= 1
    
print(cost)
    