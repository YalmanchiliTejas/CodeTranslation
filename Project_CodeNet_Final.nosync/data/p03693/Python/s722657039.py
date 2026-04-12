a,b,c = list(map(int, input().split()))
if (100*a + 10*b + c)%4 == 0:
  print('YES')
else:
  print('NO')