a, b, c = list(map(int, input().split()))
n = 10 * b + c
if n % 4 == 0:
  print('YES')
else:
  print('NO')