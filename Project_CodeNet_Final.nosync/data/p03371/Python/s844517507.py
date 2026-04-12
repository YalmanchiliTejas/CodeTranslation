a,b,c,x,y=map(int,input().split())
minpr=10e+10
memo=None
if x>=y:
  for i in range(x+1):
    price= i*a+ 2*(x-i)*c+ max(0,y-(x-i))*b
    minpr=min(price,minpr)
  print(minpr)
else:
  
  for i in range(y+1):
    price= i*b+ 2*(y-i)*c+ max(0,x-(y-i))*a
    minpr=min(price,minpr)
  print(minpr)