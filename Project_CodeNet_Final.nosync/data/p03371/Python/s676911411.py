a,b,c,x,y = map(int, input().split())
mix_price = min(a+b,c*2)
if a >= 2 * c and b >= 2 * c:
  print(2 * c * max(x,y))
elif a >= 2 * c and x >= y:
  print(x * 2 * c)
elif a >= 2 * c and x < y:
  print(x * 2 * c + (y - x) * b)
elif b >= 2 * c and x <= y:
  print(y * 2 * c)
elif b >= 2 * c and x > y:
  print(y * 2 * c + (x - y) * a)
elif a + b >= 2 * c and x >= y:
  print(y * mix_price + (x - y) * a)
elif a + b >= 2 * c and x < y:
  print(x * mix_price + (y - x) * b)
else:
  print(x * a + y * b)