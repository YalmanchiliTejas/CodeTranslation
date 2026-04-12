z,y,x=map(int,input().split())
z-=x*2+y
count=1
while(1):
  z-=y+x
  if z<0:
    break
  count+=1
print(count)