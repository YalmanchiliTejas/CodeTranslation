digits = input('')
digits = digits.split(' ')
if int(''.join(digits)) % 4 == 0:
  print('YES')
else:
  print('NO')
