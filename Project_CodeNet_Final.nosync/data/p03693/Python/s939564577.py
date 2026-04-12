r,g,b=map(int,input().split())
a=(10*g+b)%4
if a==0:
  print('YES')
else:
  print('NO')