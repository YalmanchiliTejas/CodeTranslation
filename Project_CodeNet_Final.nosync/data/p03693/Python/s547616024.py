r,g,b = map(int, input().split())

num = str(r)+str(g)+str(b)

if int(num)%4==0:
  print('YES')
else:
  print('NO')