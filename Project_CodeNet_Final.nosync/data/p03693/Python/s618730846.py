r,g,b = map(format, input().split())

if int(r+g+b) % 4 == 0:
  print('YES')
else:
  print('NO')