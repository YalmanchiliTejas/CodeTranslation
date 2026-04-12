r,g,b = input().strip().split()
n = int('{}{}{}'.format(r,g,b))
if n%4 == 0:
  print('YES')
else:
  print('NO')