import itertools
a,b,c,x,y = map(int, input().split(" "))
ans = 10 ** 11

if x > y:
  dai = a
else:
  dai = b
  
if dai >= 2 * c:
  print(c * max(x, y) * 2)

else:
  for i in range(min(x, y) + 1):
    temp = a * (x - i) + b * (y - i) + c * (i * 2)
    if ans > temp:
      ans = temp
  print(ans)