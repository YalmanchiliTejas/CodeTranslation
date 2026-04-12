a,b,c = map(str, input().split())
d = int(a+b+c)
if d%4 == 0:
  print('YES')
else:
  print('NO')