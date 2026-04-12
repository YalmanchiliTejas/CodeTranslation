r,g,b = map(int, input().split())

merge = 100*r + 10 * g + b

if merge%4 == 0:
  print('YES')
else:
  print('NO')
  