a,b,c= list(map(int,input().split()))
N = 100*a + 10*b + c
if N % 4 == 0:
  print('YES')
else:
  print('NO')