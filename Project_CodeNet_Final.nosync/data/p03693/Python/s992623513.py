r, g, b = input().split()

rgb = int(r+g+b)
rgb_2 = rgb%100

if rgb_2%4 == 0:
  print('YES')
else:
  print('NO')