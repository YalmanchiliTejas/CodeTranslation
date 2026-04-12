line = input().split(' ')
if (int(line[1])*10+int(line[2]))%4 == 0:
  print('YES')
else:
  print('NO')