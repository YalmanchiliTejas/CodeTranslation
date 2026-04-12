x,y,z=map(int,input().split())
a=x//(y+z)
if x-a*(y+z)>=z:
  print(a)
else:
  print(max(0,a-1))