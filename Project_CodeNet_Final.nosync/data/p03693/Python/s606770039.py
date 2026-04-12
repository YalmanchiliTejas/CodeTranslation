a,b,c = [int(c) for c in input().split(' ')]
i = a * 100 + b * 10 + c
if i % 4 == 0:
  print('YES')
else:
  print('NO')
