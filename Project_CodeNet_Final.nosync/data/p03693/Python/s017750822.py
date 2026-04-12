li = list(map(int,input().split()))
r = li[0]
g = li[1]
b = li[2]
ans = 100 * r + g *10 + b
if ans % 4 == 0:
  print('YES')
else:
  print('NO')