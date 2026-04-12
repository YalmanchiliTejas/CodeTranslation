r,g,b=map(int,input().split())
s=g*10+b
t=s%4
if t==0:
  print('YES')
else:
  print('NO')