X,Y,Z=[int(s) for s in input().split()]
count=0
while(X>=Y+2*Z):
  count+=1
  X-=Y+Z
print(count)