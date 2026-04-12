r,g,b = map(str, input().split())
rgb = r + g + b
if int(rgb)%4 == 0:
  print('YES')
else:
  print('NO')