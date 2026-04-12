a = list(map(str, input().split()))
a = ''.join(a)
a = int(a)
if a%4 == 0:
  print('YES')
else:
  print('NO')