r,g,b = map(int, input().split())
num = 100*r+10*g+b
mod = num % 4
if mod==0:
  print('YES')
else:
  print('NO')