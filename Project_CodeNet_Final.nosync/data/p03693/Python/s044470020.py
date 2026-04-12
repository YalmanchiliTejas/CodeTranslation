n=[int(i) for i in input().split()]
#print(n)
if (100*n[0]+10*n[1]+n[2])%4==0:
  print('YES')
else:
  print('NO')