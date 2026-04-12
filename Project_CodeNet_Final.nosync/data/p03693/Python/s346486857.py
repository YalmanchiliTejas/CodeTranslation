r,g,b = map(int,input().split())
A = 100*r + 10*g + b
if A%4 == 0:
  print('YES')

else:
  print('NO')