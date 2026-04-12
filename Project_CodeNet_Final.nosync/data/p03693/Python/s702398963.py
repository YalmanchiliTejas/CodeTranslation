r, g, b = map(int, input().split())

num = (r*100 + g*10 + b)%4

if num == 0:
  print('YES')
else:
  print('NO')
  