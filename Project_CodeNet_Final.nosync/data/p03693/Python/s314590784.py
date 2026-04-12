a = list(map(int, input().split()))
b = 100*a[0] + 10*a[1] + a[2]
if b%4 == 0:
  print('YES')
else:
  print('NO')