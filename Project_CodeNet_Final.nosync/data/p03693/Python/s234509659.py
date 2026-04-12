r,g,b = map(int, input().split())
 
sum = int(100*r + 10*g + b)
 
if sum % 4 == 0:
  print('YES')
else:
  print('NO')