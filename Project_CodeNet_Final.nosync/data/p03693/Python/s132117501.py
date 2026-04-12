r,g,b = map(int,input().split())
num = int(str(g)+str(b))
if num%4 == 0:
  print('YES')
else:
  print('NO')