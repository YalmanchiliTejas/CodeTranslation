r,g,b = map(int, input().split())
A = r*100 + g*10 + b
if A % 4 == 0:
  print('YES')
else:
  print('NO')