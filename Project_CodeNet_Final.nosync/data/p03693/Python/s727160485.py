r, g, b = map(int, input().split())
sum_value = r * 100 + g * 10 + b
if sum_value %  4 == 0:
  print('YES')
else:
  print('NO')