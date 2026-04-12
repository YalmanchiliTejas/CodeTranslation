a,b,c,x,y = map(int,input().split())
cur = a*x+b*y
z = 0
while True:
  x,y,z = x-1,y-1,z+2
  if a*max(0,x)+b*max(0,y)+c*z <= cur:
    cur = a*max(0,x)+b*max(0,y)+c*z
  else:
    print(cur)
    exit()