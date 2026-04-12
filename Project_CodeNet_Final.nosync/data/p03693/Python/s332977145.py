a,b,c=[int(i) for i in input().split()]
d=100*a+10*b+c
if d%4==0:
  print('YES')
else:
  print('NO')