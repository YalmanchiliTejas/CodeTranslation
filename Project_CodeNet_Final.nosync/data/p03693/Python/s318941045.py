
A, B, C=map(int,input().split())

N = B * 10 + C
N %= 4

if N==0:
  print('YES')
else:
  print('NO')
