x = list(map(int,input().split()))
a = 10*x[1] + x[2]
if a%4 == 0:
  print('YES')
else:
  print('NO')