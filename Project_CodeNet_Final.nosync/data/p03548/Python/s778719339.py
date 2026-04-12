X,Y,Z=map(int,input().split())
s=Z
c=0
while True:
  s+=Y+Z
  if s>X:
    break
  c+=1
print(c)