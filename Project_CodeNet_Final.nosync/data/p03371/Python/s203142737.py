a,b,c,x,y = map(int, input().split())

costs = 0

while x>0 and y>0:
  if a+b>2*c:
    costs += 2*c
  else:
    costs += a+b
  x -= 1
  y -= 1
  
if x>0:
  if a<=2*c:
    costs += x*a
  else:
    costs += x*2*c
    
if y>0:
  if b<=2*c:
    costs += y*b
  else:
    costs += y*2*c
  
print(costs)