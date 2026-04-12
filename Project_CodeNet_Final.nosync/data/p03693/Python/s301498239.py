r,g,b = [i for i in input().strip().split()]
x = int(r+g+b)
if x%4==0:
  print('YES')
else:
  print('NO')