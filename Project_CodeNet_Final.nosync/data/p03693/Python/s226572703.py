r,g,b=(int(i) for i in input().split())
a = g*10+b
if a%4==0:
  print('YES')
else:
  print('NO')