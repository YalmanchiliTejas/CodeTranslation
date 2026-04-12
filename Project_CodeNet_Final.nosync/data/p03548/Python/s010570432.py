X,Y,Z=map(int,input().split())
p=1;t=Y+2*Z
while t<X:
  t=t+Y+Z
  if t>X:
    break
  #print(t)
  p=p+1
 
print(p)