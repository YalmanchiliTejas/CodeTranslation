r,g,b=map(int,input().split())
l=(str(r)+str(g)+str(b))
if 0 == (int(l)%4):
  print('YES')
else:
  print('NO')
