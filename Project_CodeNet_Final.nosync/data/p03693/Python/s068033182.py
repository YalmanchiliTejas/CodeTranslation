a, b, c = map(int, input().split())
ans = 100 * a + 10 * b + c
if ans % 4 == 0:
  print('YES')
else:
  print('NO')