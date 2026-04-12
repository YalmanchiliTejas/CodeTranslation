a, b, c = map(str, input().split())

s = int(a + b + c)

if s % 4 == 0:
  print('YES')
else:
  print('NO')