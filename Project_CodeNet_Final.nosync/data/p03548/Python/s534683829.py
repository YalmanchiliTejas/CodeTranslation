X,Y,Z = map(int,input().split())

t = 2*Z
c = 0
while (True):
  t+=Y 
  if t>X:
    print(c)
    exit()
  t+=Z
  c+=1