A,B,C=map(str, input().split())

if int(A+B+C)%4 == 0:
  print('YES')
else:
  print('NO')