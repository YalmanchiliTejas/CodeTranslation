r, g, b = map(int, input().split())
c = int(str(r) + str(g) + str(b))

if c % 4 == 0:
  print('YES')
else:
  print('NO')