a,b,c = map(int,input().split())

r = a*100 + b*10 + c

if r%4 == 0:
  print('YES')
else:
  print('NO')