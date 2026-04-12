r, g, b = input().split()
x = r+g+b

if int(x) % 4 == 0:
  print('YES')
else:
  print('NO')