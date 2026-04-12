from sys import stdin
n = stdin.readline().rstrip().split()
if int(n[0]+n[1]+n[2])%4 == 0:
  print('YES')
else:
  print('NO')