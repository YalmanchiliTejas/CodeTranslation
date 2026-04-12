a,b,c,x,y = map(int,input().split())
if a >= c * 2 and b >= c * 2:
  ans = max(x , y) * 2 * c
elif a >= c * 2:
  ans = x * 2 * c + max(0,y - x) * b
elif b >= c * 2:
  ans = y * 2 * c + max(0,x - y) * a
elif a + b > 2 * c:
  if x >= y:
    ans = y * 2 * c + min((x - y) * a, (x - y) * 2 * c)
  else:
    ans = x * 2 * c + min((y - x) * b, (y - x) * 2 * c)
elif a + b <= 2 * c:
  ans = x * a + y * b

print(ans)