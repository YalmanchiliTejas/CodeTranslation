x,y,z=map(int,input().split())
i=0
x=x-z
while x-(y+z)>=0:
  x=x-(y+z)
  i+=1
print(i)