a,b,c,x,y = map(int,input().split())

if x >= y:
  onlyab = 2*x*c
  minab = 2*y*c + (x-y)*a
  aandb = x*a + y*b
else:
  onlyab = 2*y*c
  minab = 2*x*c + (y-x)*b
  aandb = x*a + y*b
  
print(min(onlyab,minab,aandb))