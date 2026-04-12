r,g,b=map(int,input().split())
result = (r*100+g*10+b)%4
if result==0:
  print('YES')
else:
  print('NO')